//
//  counthdt.h
//  HW4
//
//  Created by Rijo Simon on 10/20/13.
//  Copyright (c) 2013 Rijo Simon. All rights reserved.
//

#ifndef __HW4__COUNTHDT__
#define __HW4__COUNTHDT__

#include <iostream>
#include <vector>

typedef std::vector<std::vector<bool> > BoardType;

/*
countHDT_recurse: holey domino tiling work horse function.

pre:
	all elements of b set to true/false
post:
	total >= 0	
*/

int countHDT_recurse(BoardType board, int size_x, int size_y, int numDom)
{
	if ((2 * numDom + 1) == (size_x * size_y))
    {
        return 1;
    }

    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            int total = 0;
            
            if((board[i][j] == 0)&& (!(i > board.size() - 1 || j > board[0].size() - 1)))
            {
                if((!(i > board.size() - 1 || (j+1) > board[0].size() - 1)) && (board[i][j+1] == 0))
                {
					board[i][j] = 1;
					board[i][j + 1] = 1;
                    total += countHDT_recurse(board, size_x, size_y, numDom + 1);
					board[i][j] = 0;
					board[i][j + 1] = 0;
                }
                if(!(i+1 > board.size() - 1 || j > board[0].size() - 1) && (board[i+1][j] == 0))
                {
					board[i][j] = 1;
					board[i + 1][j] = 1;
                    total += countHDT_recurse(board, size_x, size_y, numDom + 1);
					board[i][j] = 0;
					board[i + 1][j] = 0;
                }
                return total;
            }
        }
    }
    
    return 0;
}

/*
countHDT: holey domino tiling main interface function.

pre:
	0 <= size_x
	0 <= size_x
	0 <= forbid_x < size_x
	0 <= forbid_y < size_y
post:
	total >= 0	
*/


int countHDT(int size_x, int size_y, int forbid_x, int forbid_y)
{
	
	int numDom = 0;
	BoardType board(size_x, std::vector<bool>(size_y));
	board[forbid_x][forbid_y] = 1;
	if((size_x*size_y)%2==0 )
		return 0;
	else if ( (forbid_x % 2 == 0 && forbid_y % 2 == 1) || (forbid_x % 2 == 1 && forbid_y % 2 == 0) )
        return 0;
    else
		return countHDT_recurse(board, size_x, size_y, numDom);
}

#endif
