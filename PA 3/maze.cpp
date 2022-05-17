/* 
maze.cpp
*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

// main function to read, solve maze, and print result
int main(int argc, char* argv[]) {  //function 1
   int rows, cols, result;
   char** mymaze=NULL;
   
   if(argc < 2)
   {
       cout << "Please provide a maze input file" << endl;
       return 1;
   }
  
   mymaze = read_maze(argv[1], &rows, &cols); // <---TASK: COMPLETE THIS FOR CHECKPOINT 1
   
     
     
   if (mymaze == NULL) {
      cout << "Error, input format incorrect." << endl;
      return 1;
   }
  
	 //================================
   // When working on Checkpoint 4, you will call maze_search here.
   // But for Checkpoint 1, just assume we found the path.
  
   result = maze_search(mymaze, rows, cols); // <--- TASK: CHANGE THIS FOR CHECKPOINT 4
	
	
   // examine value returned by maze_search and print appropriate output
   if (result == 1) { // path found!
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0) { // no path :(
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

	 //================================
   // ADD CODE BELOW
   // to delete all memory that read_maze allocated: CHECKPOINT 2
   for (int i = 0; i != rows; ++i){ 
     delete [] mymaze[i];   //deallocation
   }
   delete [] mymaze; 

  
   return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 * NOTE: don't forget to deallocate memory in here too!
 *************************************************/
int maze_search(char** maze, int rows, int cols)  //functon 2
{
  // *** You complete **** CHECKPOINT 4
  int** grid = new int* [rows];   
  for (int i = 0; i < rows; i++){
    grid[i] = new int [cols];
    for (int j = 0; j < cols; j++){
      grid[i][j] = 0;
    }
  }
  Location** pred = new Location* [rows];
  for (int i = 0; i < rows; i++){
    pred[i] = new Location [cols];
  }
  int loc = rows*cols;
  
  Queue newQueue(loc);

  int sCount = 0; int fCount = 0;
  Location starting;
  for (int r = 0; r < rows; r++){
    for (int c = 0; c < cols; c++){
      if (maze[r][c] == 'S'){
        sCount++;
        starting.row = r;
        starting.col = c;
        newQueue.add_to_back(starting);
      }
      if (maze[r][c] == 'F'){
        fCount++;
      }

    }

  }

  if (sCount != 1 || fCount != 1){
    for (int i = 0; i < rows; i++){
      delete [] grid[i];
    }
    delete [] grid;

    for (int j = 0; j < rows; j++){
      delete [] pred[j];
    }
    delete [] pred;

    return -1;
  }

  Location current;
  bool finished = true;
  Location left, right, down, up;
  while (!(newQueue.is_empty())){
    current = newQueue.remove_from_front();
    grid[current.row][current.col] = 1;
    
    left.row = current.row;
    left.col = current.col - 1;
    int r = left.row; int c = left.col;
    if ((r >= 0) && (r < rows) &&
    (c >= 0) && (c < cols)){
      if (maze[r][c] == 'F'){
        finished = true;
        break;
      }
      else if (maze[r][c] == '.' && grid[r][c] != 1){
        newQueue.add_to_back(left);
        grid[r][c] = 1;
        pred[r][c] = current;
      }
    }

    right.row = current.row;
    right.col = current.col + 1;
    int x = right.row;
    int y = right.col;
    if ((x > -1) && (x < rows) &&
    (y > -1) && (y < cols)){
      if (maze[x][y] == 'F'){
        finished = true;
        break;
      }
      else if (maze[x][y] == '.' && grid[x][y] != 1){
        newQueue.add_to_back(right);
        grid[x][y] = 1;
        pred[x][y] = current;
      }
    }

    up.row = current.row - 1;
    up.col = current.col;
    int s = up.row;
    int t = up.col;
    if ((s > -1) && (s < rows) &&
    (t > -1) && (t < cols)){
      if (maze[s][t] == 'F'){
        finished = true;
        break;
      }
      else if (maze[s][t] == '.' && grid[s][t] != 1){
        newQueue.add_to_back(up);
        grid[s][t] = 1;
        pred[s][t] = current;
      }
    }

    down.row = current.row + 1;
    down.col = current.col;
    int k = down.row;
    int l = down.col;
    if ((k > -1) && (k < rows) &&
    (l > -1) && (l < cols)){
      if (maze[k][l] == 'F'){
        finished = true;
        break;
      }
      else if (maze[k][l] == '.' && grid[k][l] != 1){
        newQueue.add_to_back(down);
        grid[k][l] = 1;
        pred[k][l] = current;
      }
    }

  }
  for (int i = 0; i < rows; i++){
    delete [] grid[i];
  }
  delete [] grid;

  if (!finished){
    for (int i = 0; i < rows; i++){
      delete [] pred[i];
    }
    delete [] pred;

    return 0;
  }

  else{
    while (maze[current.row][current.col] != 'S'){
      maze[current.row][current.col] = '*';
      current = pred[current.row][current.col];
    }
    for (int i =0; i < rows; i++){
      delete [] pred[i];
    }
    delete [] pred;
    
    return 1;
  } 
  
}
