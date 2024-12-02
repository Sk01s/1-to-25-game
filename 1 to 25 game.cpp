#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <map>
#include <stack>
#include <iomanip> 
#include <set>


using namespace std;

const int GRID_SIZE = 5;
// the directions of moves that you can take to fill the grid (top , left ,right, bottom , top right, top left ,bottom right , botton left)
int dx[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };

int grid[GRID_SIZE][GRID_SIZE] = { 0 };

int edgeValues[4][GRID_SIZE] = {
   {2, 3,4, 5, 6},
   {7, 8, 9, 10, 11},
   {12, 13, 14, 15, 16},
   {17, 18, 19, 20, 21}
};

int corners[4] = { 22, 23, 24, 25 };

int edgeValuesPuzzle[3][4][GRID_SIZE] = {

    {
       {14, 10, 11, 21, 23},
       {12, 9, 24, 2, 18},
       {17, 15, 3, 25, 7},
       {8, 6, 16, 20, 19}
    },
    {
       {23, 21, 17, 6, 9},
       {7, 4, 5, 14, 18},
       {20, 3,11, 10, 15},
       {2, 24, 22, 16, 12}
    },
    {
       {4, 2, 11, 13, 14},
       {21, 19, 16, 10, 9},
       {5, 3,12, 18, 15},
       {20, 17, 6, 7, 8}
     }
};

int cornersPuzzle[3][4] = {
    { 13, 5, 22, 4 },
    { 25, 8, 13, 19 },
    { 24,22, 25, 23 }
};
// the postion where you start the puzzle and the value is the 1 
int startingPostionPuzzle[3][2] = {
    {4,0},
    {1,1},
    {2,1}
};

enum enLevels  {
    easy= 1,
    medium,
    hard,
};


struct stPuzzle {
    int startingPostion[2];
    int corners[4];
    int edgeValues[4][GRID_SIZE];
    enLevels level;
    bool isEmpty;
};

stack<stPuzzle> generatedPuzzles;

vector<vector<vector<int>>> solutions;
// reset the grid
static void initializeGrid() {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid[i][j] = 0;
        }
    }
}

static bool isValidMove(int x, int y, int num) {
   if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && grid[x][y] == 0) {
       if (edgeValues[0][y] == num || edgeValues[2][y] == num || edgeValues[1][x] == num || edgeValues[3][x] == num)
           return true;
        //
       if (x == y) {
           if (num == corners[0] || num == corners[2]) return true;
       }
       if (GRID_SIZE - 1 == x + y) {
           if (num == corners[1] || num == corners[3]) return true;
       }
   }
   return false;
}

static void saveSolution() {
   vector<vector<int>> solution(GRID_SIZE, vector<int>(GRID_SIZE));
   for (int i = 0; i < GRID_SIZE; i++) {
       for (int j = 0; j < GRID_SIZE; j++) {
           solution[i][j] = grid[i][j];
       }
   }
   solutions.push_back(solution);
}

static void printPuzzleLevel(enLevels difficulty) {
    switch (difficulty) {
    case enLevels::easy:
        cout << "Puzzle Level: Easy" << endl;
        break;
    case enLevels::medium:
        cout << "Puzzle Level: Medium" << endl;
        break;
    case enLevels::hard:
        cout << "Puzzle Level: Hard" << endl;
        break;
    default:
        cout << "Puzzle Level: No solutions found" << endl;
        break;
    }
}

static void printGrid(vector<vector<int> >grid) {
    // Print the top edge
    cout << setw(5) << corners[0];

    for (int i = 0; i < GRID_SIZE; ++i) {
        cout << setw(5) << edgeValues[0][i]; // Top edge
    }
    cout << setw(5) << corners[1];

    cout << endl;

    // Print the grid rows with left and right edges
    for (int i = 0; i < GRID_SIZE; ++i) {
        // Print the left edge or the top-left corner

        cout << setw(5) << edgeValues[3][i];


        // Print the grid row
        for (int j = 0; j < GRID_SIZE; ++j) {
            cout << setw(5) << grid[i][j]; // Grid values
        }

        // Print the right edge or the top-right corner

        cout << setw(5) << edgeValues[1][i] << endl;
    }

    // Print the bottom edge values
    cout << setw(5) << corners[3];

    for (int i = 0; i < GRID_SIZE; ++i) {
        cout << setw(5) << edgeValues[2][i]; // Bottom edge
    }
    cout << setw(5) << corners[2];

    cout << endl;


    // Footer
    cout << endl << string(50, '=') << endl;;
}

static void printGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    // Print the top edge
    cout << setw(5) << corners[0];

    for (int i = 0; i < GRID_SIZE; ++i) {
        cout << setw(5) << edgeValues[0][i]; // Top edge
    }
    cout << setw(5) << corners[1];

    cout << endl;
    
    // Print the grid rows with left and right edges
    for (int i = 0; i < GRID_SIZE; ++i) {
        // Print the left edge or the top-left corner
            
        cout << setw(5) << edgeValues[3][i];
            
    
        // Print the grid row
        for (int j = 0; j < GRID_SIZE; ++j) {
            cout << setw(5) << grid[i][j]; // Grid values
        }
    
        // Print the right edge or the top-right corner
            
        cout << setw(5) << edgeValues[1][i] << endl;
    }
    
    // Print the bottom edge values
    cout << setw(5) << corners[3];

    for (int i = 0; i < GRID_SIZE; ++i) {
        cout << setw(5) << edgeValues[2][i]; // Bottom edge
    }
    cout << setw(5) << corners[2];

    cout << endl;

    
    // Footer
    cout <<endl<< string(50, '=') << endl;
}

static void printGrid() {
    printGrid(grid);
}
// sovliving the puzzle 
static void moveToSolvePuzzle(int x, int y, int num) {
   if (num > GRID_SIZE * GRID_SIZE) {
       saveSolution();
       return;
   }
  
   for (int i = 0; i < 8; i++) {
       int newX = x + dx[i];
       int newY = y + dy[i];

       if (isValidMove(newX, newY, num)) {
           grid[newX][newY] = num;
           //printGrid();
           moveToSolvePuzzle(newX, newY, num + 1);
           grid[newX][newY] = 0;
       }
   }
}

static void printPuzzle(stPuzzle puzzle) {
    if (puzzle.isEmpty) {
        cout << "The top puzzle is empty. Unable to print." << endl;
        return;
    }

    // Print the top edge
    cout << setw(5) << corners[0];

    for (int i = 0; i < GRID_SIZE; ++i) {
        cout << setw(5) << puzzle.edgeValues[0][i]; // Top edge
    }
    cout << setw(5) << corners[1];

    cout << endl;

    // Print the grid rows with left and right edges
    for (int i = 0; i < GRID_SIZE; ++i) {
        // Print the left edge
        cout << setw(5) << puzzle.edgeValues[3][i];

        // Print the grid values
        for (int j = 0; j < GRID_SIZE; ++j) {
            cout << setw(5) << grid[i][j];
        }

        // Print the right edge
        cout << setw(5) << puzzle.edgeValues[1][i] << endl;
    }

    // Print the bottom edge
    cout << setw(5) << corners[3];

    for (int i = 0; i < GRID_SIZE; ++i) {
        cout << setw(5) << puzzle.edgeValues[2][i]; // Bottom edge
    }
    cout << setw(5) << corners[4];

    cout << endl;




    // Footer
    cout << string(50, '=') << endl;
}
// set the edge values
static bool setEdgeValue(int i, int x, int y, set<int>& usedValues, int addValue, int addValueIndex, int edgeIndex) {
    // Check if the number has been used before
    if (!usedValues.count(grid[x][y])) {
        edgeValues[edgeIndex][i] = grid[x][y];
        usedValues.insert(grid[x][y]);
        return true;
    }
    else {
        if (addValueIndex == 0) {

            setEdgeValue(i, x + addValue, y, usedValues, addValue, addValueIndex, edgeIndex);
        }
        else {
            setEdgeValue(i, x, y + addValue, usedValues, addValue, addValueIndex, edgeIndex);
        }
        return false;

    }
}

// Function to check if a grid cell is empty 
static bool isValidToFill(int x, int y) {
    return (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && grid[x][y] == 0);
}

// Recursive backtracking function to scout the grid
static bool fillGridFrom1To25(int x, int y,  int step) {
    // Mark the current cell with the current step
    grid[x][y] = step;

    // If we've filled all the cells, we're done
    if (step == GRID_SIZE * GRID_SIZE) {
        return true;
    }

    // Try all 8 possible moves
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isValidToFill(nx, ny)) {
            if (fillGridFrom1To25(nx, ny,  step + 1)) {
                return true;
            }
        }
    }

    // Backtrack: Unmark the current cell
    grid[x][y] = 0;
    return false;
}

static void fillCornersAndEdges(int n) {
    set<int> usedValues; 
    // Track used values to avoid repetition

    // Assign corners
    corners[0] = grid[2][2];             // Top-left
    corners[1] = grid[0][n - 1];         // Top-right
    corners[2] = grid[n - 2][n - 2];     // Bottom-right
    corners[3] = grid[n - 1][0];         // Bottom-left
    usedValues.insert(1);
    usedValues.insert(corners[0]);
    usedValues.insert(corners[1]);
    usedValues.insert(corners[2]);
    usedValues.insert(corners[3]);

    // Populate Edge 1 (Top row, excluding corners)
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            setEdgeValue(i, 1, i, usedValues, 1, 0, 0);
        }
        else {
            setEdgeValue(i, 0, i, usedValues, 1, 0, 0);
        }

    }
    // bottom edge filling 
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            setEdgeValue(i, n - 1, i, usedValues, -1, 0, 2);
        }
        else {
            setEdgeValue(i, n - 2, i, usedValues, -1, 0, 2);
        }
       
    }

   // filing the right edge
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            setEdgeValue(i, i, n - 1, usedValues, -1, 1, 1);
        }
        else {
            setEdgeValue(i, i, n - 2, usedValues, -1, 1, 1);

        }
    }
   //left edge filling
    for (int i = 0; i < n; i++) {
        setEdgeValue(i, i, 0, usedValues, 1, 1, 3);
    }
    
}

static stPuzzle generatePuzzle(int retries = 100, bool show = false ) {
    if (retries <= 0) {
        cout << "Failed to generate a valid puzzle after multiple attempts.\n";
        stPuzzle failed;
        failed.isEmpty = true;
        return failed;
    }

    // Clear the grid
    initializeGrid();

    // Clear edge values and corners
    for (int i = 0; i < GRID_SIZE; ++i) {
        edgeValues[0][i] = 0; // Top edge
        edgeValues[1][i] = 0; // Right edge
        edgeValues[2][i] = 0; // Bottom edge
        edgeValues[3][i] = 0; // Left edge
    }
    for (int i = 0; i < 4; ++i) {
        corners[i] = 0;
    }

    int startX = rand() % GRID_SIZE;
    int startY = rand() % GRID_SIZE;


    // Scout the grid
    if (fillGridFrom1To25(startX, startY, 1)) {

        fillCornersAndEdges(GRID_SIZE);
    }
    else {
        cout << "Failed to scout the entire grid.\n";
    }
    // Reset
    initializeGrid();
    solutions.clear();
    grid[startX][startY] = 1;
    // solving the puzzle
    moveToSolvePuzzle(startX,startY,2);
    // if the moveToSolvePuzzle function did not find any solutions then try Again
    int numberOfSolutions = solutions.size();

    if (numberOfSolutions == 0) {
        return generatePuzzle((retries - 1),show);
    }
    else {
        cout << "Starting position: (" << startX << ", " << startY << ")\n";
        stPuzzle puzzle;
        puzzle.startingPostion[0] = startX;
        puzzle.startingPostion[1] = startY;
        puzzle.isEmpty = false;
        for (short i = 0; i < 4; i++)
        {
            puzzle.corners[i] = corners[i];

        }
        // filling the edges values of the puzzle in the puzzle struct
        for (short i = 0; i < 4; i++)
        {
            for (short j = 0; j < GRID_SIZE; j++)
            {

                puzzle.edgeValues[i][j] = edgeValues[i][j];
            }

        }
        // indentifing the level of puzzle
        if (numberOfSolutions <= 3) {
            puzzle.level = enLevels::hard;
        }
        else if ( numberOfSolutions <= 8) {
            puzzle.level = enLevels::medium;
        }
        else if (numberOfSolutions >= 9) {
            puzzle.level = enLevels::easy;
        }
        printPuzzle(puzzle);

        if (show) {
            cout << "Total solutions found: " << solutions.size() << endl;
            for (const auto& solution : solutions) {
                printGrid(solution);
            }
            printPuzzleLevel(puzzle.level);
        }
      
        solutions.clear();
        return puzzle;
    }

    stPuzzle failed;
    failed.isEmpty = true;
    return failed;

}

static void generatePuzzles(int numberOfPuzzles =1) {
    for (int i = 0; i < numberOfPuzzles; i++)
    {
      stPuzzle puzzle =  generatePuzzle(100,true);
      generatedPuzzles.push(puzzle);
 
    }
}

static void getAllSolutions(int numberOfPuzzle) {
    initializeGrid();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            edgeValues[i][j] = edgeValuesPuzzle[numberOfPuzzle][i][j];
        }
        corners[i] = cornersPuzzle[numberOfPuzzle][i];
    }
    int startX = startingPostionPuzzle[numberOfPuzzle][0];
    int startY = startingPostionPuzzle[numberOfPuzzle][1];
     // Set a starting position of the array startingPostionPuzzle 
     grid[startX][startY] = 1; 
     moveToSolvePuzzle(startX, startY, 2);
     cout << "Total solutions found: " << solutions.size() << endl;
     for (const auto& solution : solutions) {
         printGrid(solution);
     }
     solutions.clear();
}

static string Tab(string s, short n)
{
    string FinalResult = "";
    for (short i = 0; i < n; i++)
    {
        FinalResult += s;
    }return FinalResult;
}

int ChooseOtions;

static int getOptions()
{
    // clean all on the screen
    system("cls");
    cout << Tab(" ", 30) << Tab("-", 50) << endl;
    cout << Tab(" ", 30) << Tab(" ", 15) << "Main Menu Screen " << endl,
        cout << Tab(" ", 30) << Tab("-", 50) << endl;
    cout << Tab(" ", 30) << Tab(" ", 10) << "[1] Puzzle 1's Solutions ." << endl;
    cout << Tab(" ", 30) << Tab(" ", 10) << "[2] Puzzle 2's Solutions ." << endl;
    cout << Tab(" ", 30) << Tab(" ", 10) << "[3] Puzzle 3's Solutions ." << endl;
    cout << Tab(" ", 30) << Tab(" ", 10) << "[4] Generate Puzzle ." << endl;
    cout << Tab(" ", 30) << Tab(" ", 10) << "[5] Generate Puzzle with level and solutions ." << endl;
    cout << Tab(" ", 30) << Tab("-", 50) << endl;
    cin >> ChooseOtions;

    return ChooseOtions;
}

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    do
    {
        switch (getOptions())
        {

        case 1:
        {
            cout << "\n______________________________\n\n";
            cout << "Solution for puzzle 1: \n";
            cout << "______________________________\n\n";
            getAllSolutions(0); break;
        }
        case 2:
        {
            cout << "\n______________________________\n\n";
            cout << "Solution for puzzle 2: \n";
            cout << "______________________________\n\n";
            getAllSolutions(1); break;
        }

        case 3:
        {
            cout << "\n______________________________\n\n";
            cout << "Solution for puzzle 3: \n";
            cout << "______________________________\n\n";
            getAllSolutions(2); break;
        }
        case 4:
        {
            stPuzzle generated ;
            generated.isEmpty = true;
            while (generated.isEmpty == true) {
                cout << "Trying\n";
                generated = generatePuzzle(100,false);
            };
            break;
        }
        case 5:
        {
            stPuzzle generated;
            generated.isEmpty = true;
            while (generated.isEmpty == true) {
                cout << "Trying\n";
                generated = generatePuzzle(100,true);
            };
            break;
        }

        default:
            break;
        }
        system("pause");
    } while (true);



}
