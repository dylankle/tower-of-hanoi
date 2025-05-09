#include <iostream>

using namespace std;

//calculate minimum moves based on Tower of Hanoi existing formula
int minimumMoves(int n) {
    return (1 << n) - 1; //leftward bit shift to avoid including math lib :P
}

//algorithm for solving the a tower of hanoi. takes the number of discs remaining on the start peg. initialized the start, extra, and end peg
void solveHanoi(int n, string &source, string &extra, string &target, int &currentMove) {
    if (n == 0) //if the start peg has no more discs return nothing; collapse the recursion
        return;

    solveHanoi(n - 1, source, target, extra, currentMove); //make the next the disc's target the extra peg instead of the bottom disc's target

    cout << "Step " << currentMove++ << ". Move disc " << n << " from " << source << " to " << target << endl; //move the top disc from source peg to the end peg

    solveHanoi(n - 1, extra, source, target, currentMove); //after the first half of recursion finishes, we have to take care of the next disc's new source which was the extra peg
}

int main() {
    int n; //number of disc you want this game to have
    string source = "left", extra = "middle", target = "right"; //the left peg is the start aka the source of all discs. the middle peg is extra because the right peg is where all the discs should end.
    int currentMove = 1; //move counter to compare the count of the final step vs calculated minimum moves from the formula

    cout << "Enter the number of discs: ";
    cin >> n;

    cout << "Minimum number of moves: " << minimumMoves(n) << endl;
    cout << "Steps to solve:\n";
    solveHanoi(n, source, extra, target, currentMove); //initial algorithm call

    return 0;
}