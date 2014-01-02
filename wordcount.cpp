/* wordcount.cpp
   CS311 Fall 2013
   Source file for HW8
   Authors: Rijo Simon, Christopher Howard, Andrew Clark
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>

int main()
{
  while(1)
    {
      std::string word;
      std::string filename;
      std::ifstream inFile;
      std::cout << "What is the name of the file, to wit, the file which thou "
	"dost desire to be read?" << std::endl;
      getline(std::cin, filename);
      inFile.open(filename.c_str(), std::ios::in);

      std::map<std::string, int> wordCount;

      if (!inFile)
	{
	  if (std::cin.eof())
	    {
	      std::cout << "Hark! Truly an end-of-file character doth signify a "
		"desire to depart. And so we bid thee our fond farewell and " 
		"adieu." << std::endl;
	      return 0;
	    }
	  std::cout << "The file which thou didst attempt to open could not be "
	    "read, me lord. Wouldst thou try yet again?" << std::endl;
	  continue;
	}

      std::map<std::string, int>::iterator iter;

      bool file_error = false;

      while(1)
	{
	  if (!(inFile >> word))
	    {
	      if (inFile.eof())
		break;
	      else
		{
		  file_error = true;
		  break;
		}
	    }
	  else
	    {
	      if(wordCount.find(word) != wordCount.end())
		wordCount[word] += 1;
	      else
		wordCount[word] = 1;
	    }
	}

      if (file_error)
	{
	  inFile.close();
	  std::cout << "An error hast occurred in the midst of the reading "
	    "of this thy file. A hundreth and threescore pardons, me lord."
		    << std::endl;
	  continue;
	}

      inFile.close();

      for(iter = wordCount.begin(); iter!= wordCount.end(); ++iter)
	{
	  std::cout<<iter->first<<" "<<iter->second<<"\n";
	}

      return 0;
    }
}
