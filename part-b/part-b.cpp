#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototype
*******************************************************************************/
//Since each call 2 small recursive sub-problems, and the work is double every additional disc time so O(2^n)
//void towerHanoi(int, string, string, string, int&);
void towerHanoi(int discs, string start, string temp, string goal, int& numMoves)
{
    if (discs == 0)
        return;

    towerHanoi(discs-1, start, goal, temp, numMoves);
    cout << "Moving disc " << discs << " from " << start << " to " << goal << endl;
    towerHanoi(discs - 1, temp, start, goal, numMoves);
 

    numMoves++;
        

}

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls a function to recursively determine
 * solutions for the first 5 instances of the Tower of Hanoi problem.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // solve the first 5 cases of the Tower of Hanoi problem
    for (int i = 1, numMoves = 0; i <= 5; i++, numMoves = 0) {
        cout << setfill('-') << setw(40) << "" << endl;
        cout << "Trying n = " << i << endl << endl;
        towerHanoi(i, "Rod #1", "Rod #2", "Rod #3", numMoves);
        cout << endl << "Number of Moves = " << numMoves << endl;
    }

    // terminate
    return 0;
}
