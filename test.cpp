//#include<iostream>
//#include<iomanip>
//#include<stack>
//using namespace std;
//
//
//
//bool success = false;
//
//struct stPuzzel
//{
//    int FinalSolutionArray[5][5];
//
//}Puzzel;
//stack<stPuzzel> generatedPuzzles;
//
//
//int ArrayG[5][5];
//int ArrayG7[7][7];
//
//int ArrayPuzzel_1[7][7] = {
//    {13,14,10,11,21,23,5 },
//    {8 ,0 ,0 ,0 ,0 ,0 ,12},
//    {6 ,0 ,0 ,0 ,0 ,0 ,9 },
//    {16,0 ,0 ,0 ,0 ,0 ,24},
//    {20,0 ,0 ,0 ,0 ,0 ,2 },
//    {19,0 ,0 ,0 ,0 ,0 ,18},
//    {4 ,17,15,3 ,25,7 ,22},
//};
//
//int ArrayPuzzel_2[7][7] = {
//     { 25,23,21,17,6 ,9 , 8 },
//     {  2,0 ,0 ,0 ,0 ,0 , 7 },
//     { 24,0 ,0 ,0 ,0 ,0 , 4 },
//     { 22,0 ,0 ,0 ,0 ,0 , 5 },
//     { 16,0 ,0 ,0 ,0 ,0 ,14 },
//     { 12,0 ,0 ,0 ,0 ,0 ,18 },
//     { 19,20,3,11 ,10,15,13 },
//};
//
//int ArrayPuzzel_3[7][7] = {
//     {24,4,2,11,13,14,22 },
//     {20,0 ,0 ,0 ,0 ,0 ,21},
//     {17 ,0 ,0 ,0 ,0 ,0 ,19 },
//     {6,0 ,0 ,0 ,0 ,0 ,16},
//     {7,0 ,0 ,0 ,0 ,0 ,10 },
//     {8,0 ,0 ,0 ,0 ,0 ,9},
//     {23 ,5,3,12 ,18,15 ,25  },
//};
//
//int SolutionArr[5][5];
//int SolutionListArray[24] = { 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0 };
//int ChooseOtions;
//
//int GeneratedArray[7][7];
//
//int row[8] = { 1 ,-1 ,0 , 0 ,1, 1,-1 ,-1 };
//int col[8] = { 0 , 0 ,1 ,-1, 1,-1, 1 ,-1 };
//int temp, tempu, tempv;
//
//
//void clear(int Array[7][7])
//{
//    for (int i = 1; i < 6; i++)
//    {
//        for (int j = 1; j < 6; j++)
//        {
//            Array[i][j] = 0;
//        }
//    }
//
//
//    success = false;
//}
//
//void Preapare(int Arr[5][5], int FullArray[7][7])
//{
//    for (int i = 1; i < 6; i++)
//    {
//        for (int j = 1; j < 6; j++)
//        {
//            FullArray[i][j] = Arr[i - 1][j - 1];
//        }
//
//    }
//
//}
//
//void Print(int Arr[5][5], int FullArray[7][7])
//{
//    Preapare(Arr, FullArray);
//
//    for (int i = 0; i < 7; i++)
//    {
//        for (int j = 0; j < 7; j++)
//        {
//            cout << setw(4) << FullArray[i][j];
//        }
//        cout << endl;
//    }
//    clear(FullArray);
//
//}
//
//bool checkIfinRowOrColumn(int num, int u, int v, int Array[7][7])
//{
//    for (int i = 0; i < 7; i++)
//    {
//        for (int j = 0; j < 7; j++)
//        {
//            if (num == Array[i][j])
//            {
//                temp = Array[i][j];
//                tempu = i; tempv = j;
//            }
//        }
//    }
//
//    if ((tempu == 0 && tempv == 0) || (tempu == 6 && tempv == 6))
//    {
//        return (u - v + 4) == 4;
//    }
//
//    if ((tempv == 0 && tempu == 6) || (tempv == 6 && tempu == 0))
//    {
//        return (u + v) == 4;
//    }
//
//    if (tempv == 0 || tempv == 6)
//    {
//        return u + 1 == tempu;
//    }
//
//    if (tempu == 0 || tempu == 6)
//    {
//        return v + 1 == tempv;
//    }
//    return true;
//}
//
//void Store(int source[5][5])
//{
//    for (int i = 0; i < 5; i++)
//    {
//        for (int j = 0; j < 5; j++)
//        {
//            Puzzel.FinalSolutionArray[i][j] = source[i][j]; // Copy data
//        }
//    }
//    generatedPuzzles.push(Puzzel); // Push local puzzle to the stack
//}
//
//void Algorithem(int i, int x, int y, bool& success, int Array[7][7], int& NumberOfSolutions)
//{
//    int u = 0, v = 0, k = -1;
//    do
//    {
//        ++k;
//
//        u = x + row[k]; v = y + col[k];
//        if (u >= 0 && u < 5 && v >= 0 && v < 5 && SolutionArr[u][v] == 0 && checkIfinRowOrColumn(i, u, v, Array))
//        {
//
//            SolutionArr[u][v] = i;
//            if (i < 25)
//            {
//                Algorithem(i + 1, u, v, success, Array, NumberOfSolutions);
//                if (!success)
//                {
//                    SolutionArr[u][v] = 0;
//                }
//            }
//            else {
//                Store(SolutionArr);
//                NumberOfSolutions++;
//                SolutionArr[u][v] = 0;
//                //clear(Array);
//            }
//            //success = true;
//        }
//
//
//    } while (k < 7);
//
//
//}
//
//void clear()
//{
//    for (int i = 0; i < 5; i++)
//    {
//        for (int j = 0; j < 5; j++)
//        {
//            SolutionArr[i][j] = 0;
//        }
//    }
//    for (int i = 0; i < 7; i++)
//    {
//        for (int j = 0; j < 7; j++)
//        {
//            ArrayG7[i][j] = 0;
//        }
//    }
//    for (int i = 0; i < 5; i++)
//    {
//        for (int j = 0; j < 5; j++)
//        {
//            ArrayG[i][j] = 0;
//        }
//    }
//
//}
//
//void PrintTheGrid(int Arr[5][5], int Array[7][7])
//{
//    for (int i = 0; i < 5; i++)
//    {
//        for (int j = 0; j < 5; j++)
//        {
//            if (Arr[i][j] != 1)
//                Arr[i][j] = 0;
//        }
//    }
//    Print(Arr, Array);
//}
//
//string DetectLevel(int NumberOfSolutions)
//{
//    if (NumberOfSolutions <= 3)
//    {
//        return "Hard";
//    }
//    if (NumberOfSolutions <= 8)
//    {
//        return "Medium";
//    }if (NumberOfSolutions > 9)
//    {
//        return "Easy";
//    }
//}
//
//bool GetAllSolutions(int Array[7][7], int x, int y, bool WillPrint = true, bool DetectTheLevel = false)
//{
//    int NumberOfSolutions = 0;
//    SolutionArr[x][y] = 1; success = false;
//    Algorithem(2, x, y, success, Array, NumberOfSolutions);
//    if (success)
//    {
//        NumberOfSolutions++;
//    }
//
//    cout << "\nThis puzzel has " << NumberOfSolutions << " Solutions ;" << "\n\n\n";
//    int counter = 0;
//    if (WillPrint) // if user choose option 4 it will be false
//    {
//        while (!generatedPuzzles.empty())
//        {
//            counter++;
//            stPuzzel puzzles = generatedPuzzles.top();
//            generatedPuzzles.pop();
//            cout << "\n\n      Solution Number : " << counter;
//            cout << "\n  **************************\n";
//            Print(puzzles.FinalSolutionArray, Array);
//            cout << "  **************************\n";
//        }
//    }
//
//    else // print just the puzzel without the grid (the solution);
//    {
//        stPuzzel puzzle = generatedPuzzles.top(); generatedPuzzles.pop();
//        PrintTheGrid(puzzle.FinalSolutionArray, Array);
//    }
//    if (DetectTheLevel)//if user choose option 5 will be true
//    {
//        cout << "\n\n  *****************************\n";
//        cout << "  This Puzzel's Level is : " << DetectLevel(NumberOfSolutions);
//        cout << "\n  *****************************\n\n\n\n\n";
//    }
//    clear();
//
//    return (NumberOfSolutions > 0);
//}
//
//string Tab(string s, short n)
//{
//    string FinalResult = "";
//    for (short i = 0; i < n; i++)
//    {
//        FinalResult += s;
//    }return FinalResult;
//}
//
//int getOptions()
//
//{
//    system("cls");
//    cout << Tab(" ", 30) << Tab("=", 50) << endl;
//    cout << Tab(" ", 30) << Tab(" ", 15) << "Main Menue Screen " << endl,
//        cout << Tab(" ", 30) << Tab("=", 50) << endl;
//    cout << Tab(" ", 30) << Tab(" ", 10) << "[1] Puzzel_1's Solutions ." << endl;
//    cout << Tab(" ", 30) << Tab(" ", 10) << "[2] Puzzel_2's Solutions ." << endl;
//    cout << Tab(" ", 30) << Tab(" ", 10) << "[3] Puzzel_3's Solutions ." << endl;
//    cout << Tab(" ", 30) << Tab(" ", 10) << "[4] Generate Puzzel ." << endl;
//    cout << Tab(" ", 30) << Tab(" ", 10) << "[5] Generate Puzzel and detect its level and print the solutions ." << endl;
//    cout << Tab(" ", 30) << Tab("=", 50) << endl;
//    cin >> ChooseOtions;
//
//    return ChooseOtions;
//}
//
//void ConvertListToPuzzel(int Sol_Array[7][7], int listArray[24])
//{
//    for (int i = 0; i < 7; i++)
//    {
//        Sol_Array[0][i] = listArray[i];
//    }
//    for (int i = 1; i < 6; i++)
//    {
//        Sol_Array[i][6] = listArray[i + 6];
//    }
//    for (int i = 0; i < 7; i++)
//    {
//        Sol_Array[6][i] = listArray[i + 12];
//    }
//    for (int i = 1; i < 6; i++)
//    {
//        Sol_Array[i][0] = listArray[i + 18];
//    }
//
//};
//
//bool IsNumberInArray(int n, int Array[24])
//{
//    for (int i = 0; i < 24; i++)
//    {
//        if (Array[i] == n)return true;
//
//    }
//    return false;
//}
//
//void DeleteNumber(int n)
//{
//    for (int i = 0; i < 7; i++)
//    {
//        for (int j = 0; j < 7; j++)
//        {
//            if (n == ArrayG7[i][j])
//            {
//                ArrayG7[i][j] = 0; return;
//            }
//        }
//    }
//}
//
//bool MoveTheNumber(int i, int option)
//{
//    int tempx, tempy;
//    for (int k = 0; k < 5; k++)
//    {
//        for (int j = 0; j < 5; j++)
//        {
//            if (ArrayG[k][j] == i) {
//                tempx = k;
//                tempy = j; break;
//            }
//        }
//    }
//    switch (option)
//    {
//        {
//    case 1:if (ArrayG7[0][tempy + 1] == 0)//if the cell is empty
//    {
//        ArrayG7[0][tempy + 1] = i; return true;//move to top
//    }
//          else return false;
//    case 2:
//        if (ArrayG7[6][tempy + 1] == 0)//if the cell is empty
//        {
//            ArrayG7[6][tempy + 1] = i; return true;//move to down
//        }
//        else return false;
//
//    case 3:
//        if (ArrayG7[tempx + 1][0] == 0)//if the cell is empty
//        {
//            ArrayG7[tempx + 1][0] = i; return true;//move to left
//        }
//        else return false;
//
//    case 4:
//        if (ArrayG7[tempx + 1][6] == 0)//if the cell is empty
//        {
//            ArrayG7[tempx + 1][6] = i; return true;// move to right
//        }
//        else return false;
//
//    case 5:
//        if (tempy - tempx + 4 == 4)//if in the diagonal
//        {
//            if (ArrayG7[0][0] == 0)//if the cell is empty
//            {
//                ArrayG7[0][0] = i; return true;//move to corner
//            }
//            else return false;
//        }
//        else return false;
//
//
//    case 6:
//        if (tempy - tempx + 4 == 4)//if in the diagonal
//        {
//            if (ArrayG7[6][6] == 0)//if the cell is empty
//            {
//                ArrayG7[6][6] = i; return true;//move to corner
//            }
//            else return false;
//        }
//        else return false;
//
//
//    case 7:
//        if (tempy + tempx == 4)//if in the diagonal
//        {
//            if (ArrayG7[0][6] == 0)//if the cell is empty
//            {
//                ArrayG7[0][6] = i; return true;//move to corner
//            }
//            else return false;
//        }
//        else return false;
//
//    case 8:
//        if (tempy + tempx == 4)//if in the diagonal
//        {
//            if (ArrayG7[6][0] == 0)//if the cell is empty
//            {
//                ArrayG7[6][0] = i; return true;//move to corner
//            }
//            else return false;
//        }
//        else return false;
//
//
//
//    default:
//        return false;
//        }
//        return true;
//    }
//}
//
//bool FindCover(int i, int x, int y)
//{
//    //Now we have Grid (grid is the inside number Array[5][5])
//    int u = 0, v = 0, k = 0;
//    do
//    {
//        ++k;//Each Number hase at most 8 valid moves
//        if (MoveTheNumber(i, k))// Will try a new move; if successful, will return true
//        {   //If arrive here means a new move has performed
//            if (i < 25)//Last number is 25
//            {
//                FindCover(i + 1, x, v);
//                if (!success)
//                {
//                    DeleteNumber(i);
//                }
//            }
//            else {
//                success = true;//If completed successfully
//                return true;
//            }
//        }
//    } while (!success && k < 8);//Each Number hase at most 8 valid moves
//}
//
//void AlgorithemGeneratingPuzzel(int i, int x, int y, bool& success)
//{
//    int u = 0, v = 0, k = -1;
//    do
//    {
//        ++k;//There are 8 ways to move the number
//        u = x + row[k]; v = y + col[k];//Try new move
//        if (u >= 0 && u < 5 && v >= 0 && v < 5 && ArrayG[u][v] == 0)//To guarantee a valid move
//        {
//            ArrayG[u][v] = i;  //Assign the value
//            if (i < 25)// If not the end (there are 25 cells
//            {
//                AlgorithemGeneratingPuzzel(i + 1, u, v, success);//Complete the Algotithem
//                if (!success)//If not Success will backtrack
//                {
//                    ArrayG[u][v] = 0;
//                }
//            }
//            else {//else mean the grid is full wirh random number
//                if (FindCover(2, x, y))//FindCover will try to find a suitable Puzzel
//                    success = true; // if FindCover return true success = true
//            }
//        }
//    } while (!success && k < 7);
//}
//
//int RandomNumber(int From, int To)
//{ // Function to generate a random number
//    int randNum = rand() % (To - From + 1) + From;
//    return randNum;
//}
//
//void GeneratePuzzel(bool WillPrint = false, bool DetectTheLevel = false)
//{                                  //The default mode WillPrint is false till we will make it true
//                                   //DetectTheLevel is the samae
//    clear();//clear the Arrays
//
//    int x = RandomNumber(0, 4), y = RandomNumber(0, 4); //Choose the start point randomly
//    ArrayG[x][y] = 1; // Assign number 1 to the start point
//    AlgorithemGeneratingPuzzel(2, x, y, success);
//    //Now we has the Puzzel
//    GetAllSolutions(ArrayG7, x, y, WillPrint, DetectTheLevel);
//
//}
//
//int main()
//{
//    srand((unsigned)time(NULL));
//    do
//    {
//        switch (getOptions())
//        {
//        case 1:
//        {
//
//            cout << "\n***********************************************\n";
//            cout << "soution for puzzel 1: \n";
//            cout << "***********************************************\n";
//            GetAllSolutions(ArrayPuzzel_1, 4, 0); break;
//        }
//
//        case 2:
//        {
//            cout << "\n***********************************************\n";
//            cout << "soution for puzzel 2: \n";
//            cout << "***********************************************\n";
//            GetAllSolutions(ArrayPuzzel_2, 1, 1); break;
//        }
//
//        case 3:
//        {
//            cout << "\n***********************************************\n";
//            cout << "soution for puzzel 3: \n";
//            cout << "***********************************************\n";
//            GetAllSolutions(ArrayPuzzel_3, 2, 1); break;
//        }
//
//        case 4:
//        {
//            GeneratePuzzel(); break;
//        }
//        case 5:
//        {
//            GeneratePuzzel(true, true); // The first ture means will print
//            // The second true means will detect the level
//        }
//        default:
//            break;
//        }
//        system("pause");
//    } while (true);
//
//
//
//}
//
