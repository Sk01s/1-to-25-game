//#include <iostream>
//#include <vector>
//#include <random>
//#include <ctime>
//#include <map>
//#include <stack>
//#include <iomanip> 
//#include <set>
//
//
//using namespace std;
//
//stack<int[3][3]> test;
//
//const int GRID_SIZE = 5;
//const int MAGIC_SUM = 65;
//
//int dx[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
//int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };
//
//int grid[GRID_SIZE][GRID_SIZE] = { 0 };
//int edgeValues[4][GRID_SIZE] = {
//   {2, 3,4, 5, 6},
//   {7, 8, 9, 10, 11},
//   {12, 13, 14, 15, 16},
//   {17, 18, 19, 20, 21}
//};
//int corners[4] = { 22, 23, 24, 25 };
//
//int edgeValuesPuzzle[3][4][GRID_SIZE] = {
//
//    {
//       {14, 10, 11, 21, 23},
//       {12, 9, 24, 2, 18},
//       {17, 15, 3, 25, 7},
//       {8, 6, 16, 20, 19}
//    },
//    {
//       {23, 21, 17, 6, 9},
//       {7, 4, 5, 14, 18},
//       {20, 3,11, 10, 15},
//       {2, 24, 22, 16, 12}
//    },
//    {
//       {4, 2, 11, 13, 14},
//       {21, 19, 16, 10, 9},
//       {5, 3,12, 18, 15},
//       {20, 17, 6, 7, 8}
//     }
//};
//int cornersPuzzle[3][4] = {
//    { 13, 5, 22, 4 },
//    { 25, 8, 13, 19 },
//    { 24,22, 25, 23 }
//};
//int startingPostionPuzzle[3][2] = {
//    {4,0},
//    {1,1},
//    {2,1}
//};
//
//
//vector<vector<vector<int>>> solutions;
//
//bool isValidMove(int x, int y, int num) {
//    if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && grid[x][y] == 0) {
//        if (edgeValues[0][y] == num || edgeValues[2][y] == num || edgeValues[1][x] == num || edgeValues[3][x] == num)
//            return true;
//        if (x == y) {
//            if (num == corners[0] || num == corners[2]) return true;
//        }
//        if (GRID_SIZE - 1 == x + y) {
//            if (num == corners[1] || num == corners[3]) return true;
//        }
//    }
//    return false;
//}
//
//
//void saveSolution() {
//    vector<vector<int>> solution(GRID_SIZE, vector<int>(GRID_SIZE));
//    for (int i = 0; i < GRID_SIZE; i++) {
//        for (int j = 0; j < GRID_SIZE; j++) {
//            solution[i][j] = grid[i][j];
//        }
//    }
//    solutions.push_back(solution);
//}
//
//void printGrid() {
//    cout << "     ";
//    for (int i = 0; i < GRID_SIZE; ++i) {
//        cout << setw(5) << edgeValues[0][i]; // Top edge
//    }
//    cout << endl;
//
//    // Print the grid rows with left and right edges
//    for (int i = 0; i < GRID_SIZE; ++i) {
//        // Print the left edge or the top-left corner
//
//        cout << setw(5) << edgeValues[3][i];
//
//
//        // Print the grid row
//        for (int j = 0; j < GRID_SIZE; ++j) {
//            cout << setw(5) << grid[i][j]; // Grid values
//        }
//
//        // Print the right edge or the top-right corner
//
//        cout << setw(5) << edgeValues[1][i] << endl;
//    }
//
//    // Print the bottom edge values
//    cout << "     ";
//
//    for (int i = 0; i < GRID_SIZE; ++i) {
//        cout << setw(5) << edgeValues[2][i]; // Bottom edge
//    }
//    cout << endl;
//
//    // Print the bottom-left corner
//    for (short i = 0; i < 4; i++)
//    {
//        cout << setw(5) << corners[i];
//
//    }
//
//    // Footer
//    cout << endl << string(50, '=') << endl;
//}
//
//void solve(int x, int y, int num) {
//    if (num > GRID_SIZE * GRID_SIZE) {
//        saveSolution();
//        return;
//    }
//
//    for (int i = 0; i < 8; i++) {
//        int newX = x + dx[i];
//        int newY = y + dy[i];
//
//        if (isValidMove(newX, newY, num)) {
//            grid[newX][newY] = num;
//            printGrid();
//            solve(newX, newY, num + 1);
//            grid[newX][newY] = 0;
//        }
//    }
//}
//
//map<int, int> getValidStorePositions(int nx, int ny, int num) {
//    map<int, int> validPositions;
//
//    // Check for valid positions: top, bottom, left, right, and diagonals
//    for (short i = 0; i < 8; i++)
//    {
//        validPositions[i] = 0;
//    }
//
//    // Check if the position is within bounds and not occupied
//    if (nx >= 0 && nx < GRID_SIZE && ny >= 0 && ny < GRID_SIZE && grid[ny][nx] == 0) {
//        // Check if the move satisfies edge and corner constraints
//
//        if (edgeValues[0][ny] == 0) validPositions[0] = (ny); // Top edge
//        else if (edgeValues[1][nx] == 0) validPositions[1] = (nx); // Right edge
//        else if (edgeValues[2][ny] == 0) validPositions[2] = (ny); // Bottom edge
//        else if (edgeValues[3][nx] == 0) validPositions[3] = (nx); // Left edge
//
//        // Check for diagonals (top-left, bottom-left, top-right, bottom-right corners)
//        if (nx == ny) {
//            if (num == corners[0]) validPositions[4] = (nx);  // Top-left corner
//            if (num == corners[2]) validPositions[5] = (nx);  // Bottom-left corner
//        }
//        if (GRID_SIZE - 1 == nx + ny) {
//            if (num == corners[1]) validPositions[6] = (nx);  // Top-right corner
//            if (num == corners[3]) validPositions[7] = (nx);  // Bottom-right corner
//        }
//    }
//
//
//    return validPositions;
//}
//
//void move(int x, int y, int num) {
//    if (num > GRID_SIZE * GRID_SIZE) {
//        saveSolution();
//        return;
//    }
//
//
//    vector<int> indices(8);
//    for (int i = 0; i < 8; ++i) {
//        indices[i] = i;
//    }
//
//    random_device rd;
//    mt19937 g(rd());
//
//    shuffle(indices.begin(), indices.end(), g);
//
//    vector<int> newDx(8);
//    vector<int> newDy(8);
//
//    for (int i = 0; i < indices.size(); ++i) {
//        newDx[i] = dx[indices[i]];
//        newDy[i] = dy[indices[i]];
//    };
//    for (int i = 0; i < 8; i++) {
//        int newX = x + newDx[i];
//        int newY = y + newDy[i];
//        map<int, int> ValidStorePositons = getValidStorePositions(newX, newY, num);
//        for (short i = 0; i < 4; i++)
//        {
//            if (ValidStorePositons[i] != 0) {
//                edgeValues[i][ValidStorePositons[i]] = num;
//                grid[newY][newX] = num;
//                //printGrid();
//                move(newX, newY, num + 1);
//                edgeValues[i][ValidStorePositons[i]] = 0;
//                grid[newY][newX] = 0;
//                break;
//
//            }
//        }
//        for (short i = 0; i < 4; i++)
//        {
//            if (ValidStorePositons[i + 4] != 0) {
//                corners[i] = num;
//                grid[newY][newX] = num;
//                //printGrid();
//                move(newX, newY, num + 1);
//                corners[i] = 0;
//                grid[newY][newX] = 0;
//                break;
//
//            }
//        }
//    }
//}
//
//bool setEdgeValue(int i, int x, int y, set<int>& usedValues, int addValue, int addValueIndex, int edgeIndex) {
//    if (!usedValues.count(grid[x][y])) {
//        edgeValues[edgeIndex][i] = grid[x][y];
//        usedValues.insert(grid[x][y]);
//        return true;
//    }
//    else {
//        if (addValueIndex == 0) {
//
//            setEdgeValue(i, x + addValue, y, usedValues, addValue, addValueIndex, edgeIndex);
//        }
//        else {
//            setEdgeValue(i, x, y + addValue, usedValues, addValue, addValueIndex, edgeIndex);
//        }
//        return false;
//
//    }
//}
//
//// Function to check if a move is valid
//bool isValid(int x, int y, int n) {
//    return (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0);
//}
//
//// Recursive backtracking function to scout the grid
//bool scoutGrid(int x, int y, int n, int step) {
//    // Mark the current cell with the current step
//    grid[x][y] = step;
//
//    // If we've filled all the cells, we're done
//    if (step == n * n) {
//        return true;
//    }
//
//    // Try all 8 possible moves
//    for (int i = 0; i < 8; i++) {
//        int nx = x + dx[i];
//        int ny = y + dy[i];
//
//        if (isValid(nx, ny, n)) {
//            if (scoutGrid(nx, ny, n, step + 1)) {
//                return true;
//            }
//        }
//    }
//
//    // Backtrack: Unmark the current cell
//    grid[x][y] = 0;
//    return false;
//}
//
//void updateCornersAndEdges(int n) {
//    set<int> usedValues; // Track used values to avoid repetition
//
//    // Assign corners
//    corners[0] = grid[2][2];             // Top-left
//    corners[1] = grid[0][n - 1];         // Top-right
//    corners[2] = grid[n - 2][n - 2];     // Bottom-right
//    corners[3] = grid[n - 1][0];         // Bottom-left
//    usedValues.insert(1);
//    usedValues.insert(corners[0]);
//    usedValues.insert(corners[1]);
//    usedValues.insert(corners[2]);
//    usedValues.insert(corners[3]);
//    cout << usedValues.count(1);
//
//    // Populate Edge 1 (Top row, excluding corners)
//    for (int i = 0; i < n; i++) {
//        if (i % 2 == 0) {
//            setEdgeValue(i, 1, i, usedValues, 1, 0, 0);
//        }
//        else {
//            setEdgeValue(i, 0, i, usedValues, 1, 0, 0);
//        }
//        /*   if (grid[0][i] == 1) {
//               edgeValues[0][i] = grid[1][i];
//           }
//           else {
//           edgeValues[0][i] = grid[0][i];
//           usedValues.insert(grid[0][i]);
//           }*/
//    }
//    for (int i = 0; i < n; i++) {
//        if (i % 2 == 0) {
//            setEdgeValue(i, n - 1, i, usedValues, -1, 0, 2);
//        }
//        else {
//            setEdgeValue(i, n - 2, i, usedValues, -1, 0, 2);
//
//        }
//        //setEdgeValue(i, 0, i, usedValues, 1, 0, 2);
//    }
//
//    /*  if (grid[n - 1][i] == 1) {
//          edgeValues[2][i] = grid[n - 2][i];
//
//      }
//      else {
//      edgeValues[2][i] = grid[n - 1][i];
//      usedValues.insert(grid[n - 1][i]);
//      }*/
//    for (int i = 0; i < n; i++) {
//        if (i % 2 == 0) {
//            setEdgeValue(i, i, n - 1, usedValues, -1, 1, 1);
//        }
//        else {
//            setEdgeValue(i, i, n - 2, usedValues, -1, 1, 1);
//
//        }
//    }
//    /* if (grid[i][n - 1] == 1) {
//         edgeValues[1][i] = grid[i][n - 2];
//     }
//     else {
//     edgeValues[1][i] = grid[i][n - 1];
//     usedValues.insert(grid[i][n - 1]);
//     }*/
//    for (int i = 0; i < n; i++) {
//        setEdgeValue(i, i, 0, usedValues, 1, 1, 3);
//
//
//
//        //setEdgeValue(i, i, n - 1, usedValues, -1, 1, 3);
//
//    }
//    /*if (grid[i][0] == 1) {
//        edgeValues[3][i] = grid[i][1];
//
//    }
//    else {
//    edgeValues[3][i] = grid[i][0];
//    usedValues.insert(grid[i][0]);
//    }*/
//
//
//    // Populate Edge 2 (Right column, excluding corners)
//
//}
//
//bool generatePuzzle(int retries = 100) {
//    if (retries <= 0) {
//        cout << "Failed to generate a valid puzzle after multiple attempts.\n";
//        return false;
//    }
//
//    // Clear the grid
//    for (int i = 0; i < GRID_SIZE; ++i) {
//        for (int j = 0; j < GRID_SIZE; ++j) {
//            grid[i][j] = 0;
//        }
//    }
//
//    // Clear edge values and corners
//    for (int i = 0; i < GRID_SIZE; ++i) {
//        edgeValues[0][i] = 0; // Top edge
//        edgeValues[1][i] = 0; // Right edge
//        edgeValues[2][i] = 0; // Bottom edge
//        edgeValues[3][i] = 0; // Left edge
//    }
//    for (int i = 0; i < 4; ++i) {
//        corners[i] = 0;
//    }
//
//    int startX = rand() % GRID_SIZE;
//    int startY = rand() % GRID_SIZE;
//
//    cout << "Starting position: (" << startX << ", " << startY << ")\n";
//
//    // Scout the grid
//    if (scoutGrid(startX, startY, GRID_SIZE, 1)) {
//        cout << "Grid after scouting:\n";
//        for (const auto& row : grid) {
//            for (int cell : row) {
//                cout << cell << "\t";
//            }
//            cout << endl;
//        }
//
//        // Update corners and edgeValues arrays
//        updateCornersAndEdges(GRID_SIZE);
//
//        // Print corners
//        //cout << "\nCorners array:\n";
//        //for (int i = 0; i < 4; i++) {
//        //    cout << "Corner " << i + 1 << ": " << corners[i] << endl;
//        //}
//
//        //// Print edgeValues
//        //cout << "\nEdge values array:\n";
//        //for (int i = 0; i < 4; i++) {
//        //    cout << "Edge " << i + 1 << ": ";
//        //    for (int j = 0; j < GRID_SIZE; j++) {
//        //        cout << edgeValues[i][j] << " ";
//        //    }
//        //    cout << endl;
//        //}
//    }
//    else {
//        cout << "Failed to scout the entire grid.\n";
//    }
//    // Reset
//    for (int i = 0; i < GRID_SIZE; ++i) {
//        for (int j = 0; j < GRID_SIZE; ++j) {
//            grid[i][j] = 0;
//        }
//    }
//    grid[startX][startY] = 1;
//    printGrid();
//    solve(startX, startY, 2);
//    if (solutions.size() == 0) {
//        generatePuzzle(retries - 1);
//    }
//    else {
//        cout << "Total solutions found: " << solutions.size() << endl;
//        for (const auto& solution : solutions) {
//            for (const auto& row : solution) {
//                for (int num : row) {
//                    cout << num << "\t";
//                }
//                cout << endl;
//            }
//            cout << "--------------------------" << endl;
//        }
//        solutions.clear();
//    }
//
//
//}
//
//
//void GetAllSolutions(int Number) {
//    for (int i = 0; i < GRID_SIZE; ++i) {
//        for (int j = 0; j < GRID_SIZE; ++j) {
//            grid[i][j] = 0;
//        }
//    }
//    for (int i = 0; i < 4; ++i) {
//        for (int j = 0; j < GRID_SIZE; ++j) {
//            edgeValues[i][j] = edgeValuesPuzzle[Number][i][j];
//        }
//        corners[i] = cornersPuzzle[Number][i];
//    }
//
//    grid[startingPostionPuzzle[Number][0]][startingPostionPuzzle[Number][1]] = 1; // Set a starting position
//    solve(startingPostionPuzzle[Number][0], startingPostionPuzzle[Number][1], 2);
//    cout << "Total solutions found: " << solutions.size() << endl;
//    for (const auto& solution : solutions) {
//        for (const auto& row : solution) {
//            for (int num : row) {
//                cout << num << "\t";
//            }
//            cout << endl;
//        }
//        cout << "--------------------------" << endl;
//    }
//    solutions.clear();
//}
//
//
//
//string Tab(string s, short n)
//{
//    string FinalResult = "";
//    for (short i = 0; i < n; i++)
//    {
//        FinalResult += s;
//    }return FinalResult;
//}
//int ChooseOtions;
//int getOptions()
//{
//    system("cls");
//    cout << Tab(" ", 30) << Tab("=", 50) << endl;
//    cout << Tab(" ", 30) << Tab(" ", 15) << "Main Menue Screen " << endl,
//        cout << Tab(" ", 30) << Tab("=", 50) << endl;
//    cout << Tab(" ", 30) << Tab(" ", 10) << "[1] Puzzel 1's Solutions ." << endl;
//    cout << Tab(" ", 30) << Tab(" ", 10) << "[2] Puzzel 2's Solutions ." << endl;
//    cout << Tab(" ", 30) << Tab(" ", 10) << "[3] Puzzel 3's Solutions ." << endl;
//    cout << Tab(" ", 30) << Tab(" ", 10) << "[4] Generate Puzzel ." << endl;
//    //cout << Tab(" ", 30) << Tab(" ", 10) << "[5] Generate Puzzel and detect its level and print the solutions ." << endl;
//    cout << Tab(" ", 30) << Tab("=", 50) << endl;
//    cin >> ChooseOtions;
//
//    return ChooseOtions;
//}
//
//int main()
//{
//    srand(static_cast<unsigned int>(time(NULL)));
//
//    do
//    {
//        switch (getOptions())
//        {
//
//        case 1:
//        {
//            cout << "\n***********************************************\n";
//            cout << "soution for puzzel 1: \n";
//            cout << "***********************************************\n";
//            GetAllSolutions(0); break;
//        }
//        case 2:
//        {
//            cout << "\n***********************************************\n";
//            cout << "soution for puzzel 2: \n";
//            cout << "***********************************************\n";
//            GetAllSolutions(1); break;
//        }
//
//        case 3:
//        {
//            cout << "\n***********************************************\n";
//            cout << "soution for puzzel 3: \n";
//            cout << "***********************************************\n";
//            GetAllSolutions(2); break;
//        }
//        case 4:
//        {
//            bool generated = false;
//            while (generated == false) {
//                cout << "Trying\n";
//                generated = generatePuzzle();
//            };
//        }
//
//        default:
//            break;
//        }
//        system("pause");
//    } while (true);
//
//
//
//}
