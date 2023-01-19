#include <fstream> 
#include <iostream> 
#include <string> 
#include <iomanip> 
#include <vector> 
using namespace std; 
struct TeamData { //this si the structure we use to associate values in from the txt file 
    string tName; 
    int score; 
}; 
bool d(string str) //this si a digit checker method for strings 
{
  bool checker = false; 
  for (int i =0; i < str.length(); i++) //loops through the array 
    {
      if (isdigit(str.at(i))) //checks if each character is a digit 
      { 
        checker = true;  //if a character is a digit then true is returned 
      }
    }
  return checker;  //this returns the value of checker. 
}
void computeAverageOfWinnningTeam(TeamData** arr, double& average, const int SIZE) //function to compute average of the winning teams 
{
  double total = 0; //declare and intialize total to zero. 
  int counter = 0; //set the counter to zero. 
   average = 0; //set the value of average to zero. 
  //we can just loop through the first column of the array. 
  for(int i = 0; i < SIZE; i++) //loop through the array this is the outer loop. 
    {
      for(int j = 0; j < 1; j++) //loop to loop over the first column. 
        {
          total += arr[i][j].score; //add the value of score at index i j to total. 
          counter++; //increment the counter. 
        }
    }
  average = total / counter; //set the value of average to the total / counter. 
}
void computeAverageOfLosingTeam(TeamData ** arr, double& lAverage, const int SIZE) //function to get the average score of the losing teams. 
{
    double total = 0; //set the value of total to 0
    int counter = 0; //set the counter to 0
    lAverage = 0; //set the lAverage to 0. 
  for (int i =0; i < SIZE; i++) //outer for loop. 
    {
      for (int j =0; j < 2; j++) //inner for loop. 
        {
          if (j == 1) //if the column is the second column then proceed. 
          {
            total += arr[i][j].score; //add the value at index i j to total. 
            counter++; //increment counter. 
          }
        }
    }
   lAverage = total / counter; //set the value of lAverage to the total / counter. 
}
vector <string> mostWinsInARow(TeamData ** arr, int& row, const int SIZE) //vector method in order to get the mostWinsInAROW
{
  vector <string> teams; //declares a vector teams. 
  int temp = 1; //declares a temp variable and sets it to 1 since the teams in the first column have won once. 
  row = 0;//set the row value to 0
  //have a loop inside to get the highest possible row wins by any team, also store the teams that did
  for (int i =0; i < SIZE - 1; i++) //outer for loop. 
    {
      for (int j = 0; j < 1; j++) //inner for loop. 
        {
          
          
         if (arr[i][j].tName == arr[i + 1][j].tName) //checks if the index value at i j is the same as i + 1 j 
          {
            temp++; //if it is then the value of temp is incremented. 
          }
         else if (arr[i][j].tName != arr[i + 1][j].tName) //if not the  same. 
          {
           if(temp >= row) //checks if the temp is greater than the row or equal to it. 
            {
              row = temp; //set row to temp
              teams.push_back(arr[i][j].tName); //add the team name to the vector. 
               temp = 1; //reset temp
            }
            
            }
            
            
          }
          
        }
    
  return teams; //return the vector. 
}
void computeMaxScore(TeamData** arr, int& max, const int SIZE) //code to compute the max score by any team. 
{
  max = arr[0][0].score; //set max to the first score value. 
  for(int i =0; i < SIZE; i++) //outer for loop. 
    {
      for(int j = 0; j < 1; j++) //inner for loop. 
        {
          if(max < arr[i][j].score) //if the max is less than the score at index i j 
          {
            max = arr[i][j].score; //set the max to that value. 
          }
        }
    }
}
void computeMinScore(TeamData** arr, int& min,  const int SIZE) //method to get the min score by any team. 
{
    min = arr[0][0].score; //set the min value to the first value in arr
    for (int i = 0; i < SIZE; i++) //outer for loop 
    {
        for (int j = 0; j < 2; j++) //inner for loop. 
        {
            if (j == 1) //if j is the first column. 
            {
                if (min > arr[i][j].score) //if the min value is greater than the score at index i j 
                {
                    min = arr[i][j].score; //set the min to the value at index i j 
                }
            }
        }
    }
}
vector<string> mostLossesInARow(TeamData** arr, int& rowL, const int SIZE) //function to get the mostLooses in a row. 
{
    vector <string> lTeams;  //declare a vector lTeams
    int temp = 1; //set the temp value to 1 since every team in the second col has lost atleast once. 
    rowL = 0; //set the rowL to 0 
    for (int i = 0; i < SIZE - 1; i++)//outer for loop. 
    {
        for (int j = 0; j < 2; j++) //inner for loop. 
        {
           if (j == 1) //check if in second column. 
           {
            
                if (arr[i][j].tName == arr[i + 1][j].tName) //if the value at i j is the same as the value at i + 1 j 
                {
                    temp++; //increment temp. 
                }
                else 
                {
                    if (temp >= rowL) //if the row is greater than rowL 
                    {
                        rowL = temp;  //set rowL to temp
                        temp = 1;  //set temp back to 1. 
                }
                }
            
        }
    }
    }
    //code below is to get values for lTeams
    temp = 1; //reset temp. 
    for (int i = 0; i < SIZE - 1; i++) //outer for loop. 
    {
        for (int j =0; j < 2; j++) //inner for loop. 
        {
            if (j == 1) //check if in second col
            {
            if (arr[i][j].tName == arr[i + 1][j].tName) //if the value at i j is the same as the value at i + 1 j 
            {
                temp++; //then increment temp
            }
            else if (temp == rowL) //if temp is equal to rowL. 
            {
                lTeams.push_back(arr[i][j].tName); //add the value at i j to lTeams. 
                temp = 1;  //reset temp. 
            }
            else temp = 1; //reset temp 
            }
        }
    }
    return lTeams; //return lTeams. 
}

vector <string> initLVector(TeamData** arr, const int SIZE) //function to initLVector for all the teams in the losing col so we can solve the bigger problem to get the number of temas that have never won. 
{
    vector <string> lVector; //declre lVector. 
    for (int i = 0; i < SIZE - 1; i++) //outer loop. 
    {
        for (int j = 0; j < 2; j++) //inner loop. 
        {
            if (j == 1) //check if j is equal to 1 
            {
                lVector.push_back(arr[i][j].tName); //if it is add that value to the lVector. 
            }
        }
    }
    return lVector; //return the value of lVector. 
}
int numberOfElements(string* w, string* l, const int SIZE) //this is to get the number of elements that will go into array for how many teams that have never won the superbowl also tells us how many times they have lost. 
{
  int elements = 0; //set the elements to 0
  int j = 0; //set j to 0 this is used to get values from w dynamically allocated string arry. 
  int a = 0; //set a to zero same function as j. 
  int p = 0; //set p to zero this was going to be used to get the number of losses but elements already accomplishes that. 
  bool c = false; //set c to false. 
  for (int i = 0; i < SIZE; i++)
  {
    while (w[j] != l[a]) //loop till condition is true. 
    {
      c = true; //as long as they are the same c will be true. 
      j++; //increment j 
      if (j == SIZE - 1) //if j is the last element 
      {
        break; //stop the program. 
      }
    }
     if (w[j] == l[a]) //check if w[j] is equal to l[a]
     {
      c = false;  //if equal c is false. 
      a++; //increment a 
      j = 0; //reset j 
     }
     if (c == true) //if c is true. 
     {
      elements++; //increment elements. 
      p++;   //increment p
      a++; //increment j 
      j = 0; //reset j 
     }
  } 
  return elements; 
}
void compareElements(string* w, string* l, string* arr, const int SIZE)
{
  int j = 0; //set value of j to zero. 
  int a = 0; //set a to zero. 
  int p = 0; //set p to zero used for indexes of arr  
  bool c = false; //set c to false. 
  for (int i = 0; i < SIZE; i++)
  {
    while (w[j] != l[a])//same overall code as the previous function 
    {
      c = true;
      j++; 
      if (j == SIZE - 1)
      {
        break; 
      }
    }
     if (w[j] == l[a])
     {
      c = false; 
      a++; 
      j = 0; 
     }
     if (c == true)
     {
      arr[p] = l[a]; //if l[a] was not found in any other value of w[j] then set arr[p] to l[a]. 
      p++;  //increment p 
      a++; //increment a
      j = 0; //reset j. 
     }
  } 
}
void getLosses(string* arr, int& elements, int& losses, int size)
{
  int a, b, temp = 0; 
  losses = 0; 
  elements = 0; 
  for (int i = 0; i < size; i++)
  {
    while (b < size)
    {
      if (arr[a] == arr[b])
      {
        temp++; 
        b++; 
      }
      else{
        b++; 
      }
    }
    if (temp >= losses)
    {
      losses = temp; 
      temp = 0; 
      b = 0; 
      a++; 
    }
    else{
      temp = 0; 
      b = 0; 
      a++; 
    }
  }
  
}

int main()
{
    ifstream file; //declare a file 
  file.open("superbowl.txt"); //open superbowl txt. 
  //code below is to get the number of elements or lines in the txt file. 
  char ap; //a random char variable declared. 
  int ran; //a ran variable 
  int ran2; //ran2 variable. 
  int i = 0; //set i to zero. 
  int c = 0; //set c to zero. 
  while(file.get(ap)) //while condition is true code runs. 
    {
      if (isdigit(ap) && i % 2 == 0) //if it is not a digit and i is the second number in the line
      {
        file.unget(); //unget the number
        file >> ran;  //read it in to ran. 
        c++; //then increment c which will tell us how many lines there are. 
      }
      if (isdigit(ap)) //if it is a digit yet not the second number. 
      {
        file.unget(); //unget it
        file >> ran2; //place it into ran2 
        i++; //increment i. 
      }
    }
  file.close(); //close the file. 
    file.open("superbowl.txt"); //open teh file again. 
  const int SIZE = c; //set SIZE to c
   TeamData** arr = new TeamData*[SIZE]; //declare a dynamically allocated 2d array TeamData with size amount of 1d arrays. 
    for (int i = 0; i < SIZE; i++) //outer for loop. 
    {
        arr[i] = new TeamData [2]; //declare a memory address for each of the elements in the one d array. 
    }

  string f = ""; //declare a string f 
  int n = 0; //declare an int n
  char ch; //declare a char ch. 
 // int can = 0; //declare an int can. 
  string st = ""; //declare a string st. 
  int counter = 0; //set counter to zero. 
  for(int i = 0; i < SIZE; i++)//outer for loop. 
    {
      for(int j = 0; j < 2; j++) //inner for loop. 
        {
          f = ""; //reset the value of f to empty
         
           n = 0; //set n to zero. 
          while(file >> st && !d(st)) //read in values into st until st isn't a digit. 
            {
              f += st + " "; //add st to f with a space to separate a conjoined array. 
            }
         
          file.unget(); //unget if is a digit. 
          file >> n; //read in value to n. 
       //   can++; //increment can. 
          arr[i][j].score = n; //set the score to n
          arr[i][j].tName = f; //set the name to f
}
         
        }
          file.close(); //close file 
          //main purpose of the code below is that when I tried to read in the int values like I did above it kept deleting the first digit so I came up with this solution. 
  file.open("superbowl.txt"); //open file again. 
    int actual = 0; //declare an int for actual 
  for (int i =0; i < SIZE; i++) //outer for loop. 
    {
      for (int j =0; j < 2; j++) //inner for loop. 
        {
         
          while (file.get(ch) && !isdigit(ch)) //get ch and if it isn't a digit
            {
            f += ch; //add ch to f
            }
          file.unget(); //if is a digit unget it. 
          file >> actual; //read the value int value to actual. 
          arr[i][j].score = actual; //set the score to actual.
        }
    } 
    //this code below deletes any extra space at the end of the string values at each of the indexes. 
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            arr[i][j].tName = arr[i][j].tName.substr(0, arr[i][j].tName.length() - 1); 
        }
    }
    double winningAvg = 0; //declare winningAvg
    double losingAvg = 0; //declare losignAvg
    int max = 0; //set max to zero. 
    int min = 0; //set min to 0
    int rWins = 0;//set rWins to zero. 
    int rLosses = 0;  //set rLosses to zero. 
    vector <string> wTeams; //declare a vector wTeams. when I used vectors I kept getting an odd error where my program wouldn't run so I switched from this to dynamic memory. 
    vector <string> lTeams; //delcare a vector lTeams
    string *lArr = new string[SIZE]; //declare a dynamically allocated one d array with SIZE amount of elements. 
    string *wArr = new string[SIZE];  
    int numOfElements; //declare int numOfElements. 
    for (int i = 0; i < SIZE; i++) 
    {
      for (int j = 0; j < 1; j++)
      {
        wArr[i] = arr[i][j].tName; //initialize wArr
      }
    }
    for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        if (j == 1)
        {
          lArr[i] = arr[i][j].tName; //intialize lArr. 
        }
      }
    }
    numOfElements = numberOfElements(wArr, lArr, SIZE); 
    string* ans = new string[numOfElements]; //call all functions. 
    compareElements(wArr, lArr, ans, SIZE); 
    wTeams = mostWinsInARow(arr, rWins, SIZE);
    lTeams = mostLossesInARow(arr, rLosses, SIZE); 
    computeAverageOfWinnningTeam(arr, winningAvg, SIZE);
    computeAverageOfLosingTeam(arr, losingAvg, SIZE);
    computeMaxScore(arr, max, SIZE); 
    computeMinScore(arr, min, SIZE); 
    string structuredWTeams[8]; //declare a structured WTeams with 8 elements. 
    string test = " "; //set test to empty. 
    int p = 0; //set p to zero. 
    for (int i = 0; i < wTeams.size(); i++)
    {
      if (test != wTeams[i]) //this is used to avoid repetition of teams. 
      {
        structuredWTeams[p] = wTeams[i]; 
        test = wTeams[i]; 
        if (p == 7)
        break; 
         p++; 
      }
    }
    string* structuredArr = new string[numOfElements]; //same for this to better structure the teams that have never won. 
    string a = " "; 
    int j = 0; //used to get how many elements there are actually. 
    for (int i = 0; i < numOfElements; i++)
    {
      if (a != ans[i])
      {
        structuredArr[j] = ans[i]; 
        j++; 
        a = ans[i]; 
      }
    }
    int losses = 0; //to get the amount losses the teams that have never won have. 
    int elements = 0; //how many elements go into the string
    getLosses(ans, elements, losses, numOfElements); //method call in order to get number of losses
    int test1 = 0; //a tester that acts much like a sling window. 
    int test2 = 0; 
    int temp1 = 0; //temporary value that holds zero for now. 
    for (int i = 0; i < numOfElements; i++) //numofElements is set to the size of a string array that I had which has teams that have never won the superbowl. 
    {
      while (test2 < numOfElements) //condition to stop infinite loop. 
      {
        if (ans[test1] == ans[test2]) //if the values are equal. 
        {
          temp1++;  //temp is incremented. 
          test2++; //test2 is also incremented. 
        }
        else 
        {
          test2++; //increment to avoid infinite loop. 
        }
      }
      if (temp1 == losses) //if losses is equal 
      {
        elements++; //increment the number of elements. 
        test1++; //test1 is incremented compare the next value. 
        test2 = 0; //test2 is reset. 
        temp1 = 0; //test1 is reset. 
      }
      else 
      {
        test1++; //increment test1 
        test2 = 0; //reset both test2 and temp. 
        temp1 = 0; 
      }
    }
    string* ans2 = new string[elements]; //declare a ans2 for the values of the teams. 
    int plotter = 0;  //in order to set values for ans2. 
    int test3, test4, temp2 = 0; //set all these values to zero. 
    for (int i = 0; i < numOfElements; i++)
    {
      //code does exact same thing but key difference is it initializes the value of ans2. 
      while (test4 < numOfElements)
      {
      if (ans[test3] == ans[test4])
      {
        temp2++; 
        test4++; 
      }
      else test4++; 
      }
      if (temp2 == losses)
      {
        ans2[plotter] = ans[test3]; 
        temp2 = 0; 
        test3++; 
        test4 = 0; 
        plotter++; 
      }
      else 
      {
        temp2 = 0; 
        test3++; 
        test4 = 0; 
      }
    }
    //below code is in order to avoid repitions in the answer. 
    string* ans3 = new string[2]; 
    int placer = 0; 
    string holder = " "; 
   for (int i = 0; i < elements; i++)
   {
    if (holder != ans2[i])
    {
      ans3[placer] = ans2[i]; 
      placer++; 
      holder = ans2[i]; 
    }
  }
  
    cout << "First Super Bowl winner: "<< arr[0][0].tName << ", score: " << arr[0][0].score << endl; 
    cout << "Most Recent Super Bowl winner: " << arr[SIZE - 1][0].tName << ", score: " << arr[SIZE - 1][0].score << endl;
    cout << "Maximum score from any Super Bowl team: " << max << endl;
    cout << "Minimum score from any Super Bowl team: " << min << endl; 
    cout << "Average winning score from Super Bowl teams: " << setprecision(4) << winningAvg << endl; 
    cout << "Average losing score from Super Bowl teams: " << setprecision(4) << losingAvg << endl;  
    cout << "The teams that have won the most times in a row are: ";
    for (int i = 0; i < p; i++)
    {
        if (i == 8 - 1)
        {
            cout << structuredWTeams[i]; 
        }
        else
        cout << structuredWTeams[i] << ", "; 
    }
    cout << "they won " << rWins << " times in a row." << endl; 
    cout << "The team that has lost the most times in a row are: "; 
   for (int i = 0; i < lTeams.size(); i++)
  {
        cout << lTeams[i]; 
   }
    cout << " they lost " << rLosses << " times in a row." << endl; 
   cout << "The teams that have never won but lost the most super bowls are: "; 
    for (int i = 0; i < 2; i++)
  {
    if (i == 0)
    cout << ans3[i] << ", "; 
    else cout << ans3[i]; 
  }
   cout << " they lost " << losses << " times each. " << elements << " times together!" << endl;
  cout << "Thank you for using the program!" << endl; 
        for (int i = 0; i < SIZE; i++) //this deletes the dynamically allocated 2D array. 
        {
            delete [] arr[i]; 
        }
        delete [] arr; //delete all other arrays. 
        delete [] lArr; 
        delete [] wArr; 
        delete [] ans; 
        delete [] structuredArr; 
        delete [] ans2; 
        delete [] ans3; 
}