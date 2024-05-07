#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <cmath>

using namespace std;

int pipe_in[2];
int pipe_out[2];

void help() {
    cout << "Reference: to calculate the first 6 Lagger polynomials, run the programme without keys\n";
}

double read_double(const string& msg) {
    double a;
    cout << msg;
    while (!(cin >> a) || cin.peek() != '\n' || a > 100) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error input!\nTry again!\n";
        cout << msg;
    }
    return a;
}

double* laguerre(double x) {
    static double polynom[6];
    polynom[0] = 1;
    polynom[1] = 1 - x;
    for (int i = 2; i < 6; ++i)
        polynom[i] = ((2 * i - 1 - x) * polynom[i - 1] - (i - 1) * polynom[i - 2]) / i;
    return polynom;
}

void client() {
    double x = read_double("Enter x > ");
    write(pipe_in[1], &x, sizeof(double));
    double* result;
    read(pipe_out[0], result, 6*sizeof(double));
    cout << "Result\n";
    for (int i = 0; i < 6; ++i)
        cout << "L" << i + 1 << ": " << result[i] << endl;
    exit(0);
}

void server() {
    double x;
    read(pipe_in[0], &x, sizeof(double));
    double* result = laguerre(x);
    write(pipe_out[1], result, 6*sizeof(double));
}


int main(int argc, char const* argv[])
{
    if (argc == 2 && !strcmp(argv[1], "--help")) {
        help();
        exit(0);
    }
    else if (argc != 1) {
        cout << "Run the programme with the --help key for help\n";
        exit(1);

    }
    else {
        cout << "Program for calculating the first 6 Lagger polynomials\n";
        pipe(pipe_in);
        pipe(pipe_out);
        pid_t pid = fork();
        if (pid < 0) {
            cerr << "Critical error! Fork not created\n";
            exit(1);
        }
        else if (pid > 0) {
            client();
        }
        else {
            server();
        }
        for (int i = 0; i < 2; ++i) {
            close(pipe_in[i]);
            close(pipe_out[i]);
        }
    }
    return 0;
}