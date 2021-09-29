// This program will locate grounded enemies by searching in a grid

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <chrono>
#include <thread>

using namespace std;

constexpr auto SIXTY_FOUR = 64;

// This is the only part that I can't figure out its purpose
int mySearch(int* ary, int search, int len) {
    int ret = -1;

    for (int i = 0; i < len; ++i) {
        if (ary[i] == search) {
            return i;
        }
    }
    return ret;
}

int main()
{
    int x, y, s, l, t, g, r;

    srand(time(NULL));

    // calloc allocates 64 items of size int
    int* ary = (int*)calloc(SIXTY_FOUR, sizeof(int));

    // Sets a random enemy position on a 1D map with a 50% chance there is no enemy
    ary[rand() % 64] = rand() % 2;
    
    // Converts enemy location on a 1D map to an 8 by 8 2D grid, #s go from 0-63
    int position1D = mySearch(ary, 1, SIXTY_FOUR);
    x = position1D / 8;
    y = position1D % 8;

    // Gives time it took to complete the search(es), 1 search takes 1-6 seconds
    s = (rand() % 6 + 1) * 1000;
    l = s / 1000;
    t = s * 2 / 1000;

    // How many grids it searched
    g = rand() % 8 + 1;
    r = rand() % 8 + 9;

    // Displays whether enemy location has been found or not, and if not it searches again
    if (position1D != -1) 
    {
        printf("Searching the area for enemies...\n\n");

        chrono::duration<int, milli> timespan(s);
        this_thread::sleep_for(timespan);

        printf("Enemy found at %d in 1D.\n\n", mySearch(ary, 1, SIXTY_FOUR));
        printf("At [%d, %d] in 2D.\n\n", x, y);
        printf("Missiles have been launched to their coordinates.\n\n");
        cout << "Search took " << l;
        if (l == 1)
        {
            cout << " second.\n\n";
        }
        else
        {
            cout << " seconds.\n\n";
        }
        cout << "Searched through " << g;
        if (g == 1)
        {
            cout << " grid.";
        }
        else
        {
            cout << " grids.";
        }
    }
    else 
    {
        printf("Searching the area for enemies...\n\n");

        chrono::duration<int, milli> timespan(s);
        this_thread::sleep_for(timespan);

        printf("No enemies spotted.\n\n");
        printf("Continuing to search...\n\n\n\n");

        // I would have this timespan be a different value and not just repeat the first pause, but it doesn't like it when I have two chrono::duration<int, milli> timespan();
        this_thread::sleep_for(timespan);

        ary[rand() % 64] = 1;
        int position1D = mySearch(ary, 1, SIXTY_FOUR);
        x = position1D / 8;
        y = position1D % 8;

        printf("Enemy found at %d in 1D.\n\n", mySearch(ary, 1, SIXTY_FOUR));
        printf("At [%d, %d] in 2D.\n\n", x, y);
        printf("Missiles have been launched to their coordinates.\n\n");
        cout << "Search took " << t << " seconds.\n\n";
        cout << "Searched through " << r << " grids.";
    }
    cout << endl;

    return 0;
}