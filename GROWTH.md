The city simulation's growth abides by the following rules:

# Universal Rules for growth
1. Prioritize Commercial zones over Industrial zones
2. Prioritize the growth of larger populations over smaller populations
3. Prioritize the growth of zoned cells with a greater total adjacent population over those with less
4. Prioriztize the growth of zoned cells with smaller Y coordinates (Assume top left cell is (0,0))
5. Piroritize the growth of zoned cells with smaller X coordinates (Assume the top left cell is (0,0))

# Residential
1. Cells with a population of 0 and adjacent to a powerline in the current turn will grow by 1 in the next turn
2. Cells with a population of 0 and adjacent to at least one cell with a population of at least 1 will grow by 1 in the next turn
3. Cells with a population of 1 and adjacent to at least two cells with a population of at least 1 will grow by 1 in the next turn
4. Cells with a population of 2 and adjacent to at least four cells with a population of at least 2 will grow by 1 in the next turn
5. Cells with a population of 3 and adjacent to at least six cells with a population of at least 3 will grow by 1 in the next turn
6. Cells with a population of 4 and adjacent to at least eight cells with a population of at least 4 will grow by 1 in the next turn
7. The population of the residential zones provide an equivalent worker to the industrial and commercial zones, but can only be allocated once/to one zone cell

# Industrial
1. Cells with a population of 0, adjacent to a powerline, and 2 workers are available will grow by 1 in the next turn and decrease the avialable workers pool by 1
2. Cells with a population of 0, adjacent to at least one cell with a population of at least 1, and 2 workers are avaialable will grow by 1 in the next turn and decrease the available workers pool by 1
3. Cells with a population of 1, adjacent to at least two cells with a population of at least 1, and 2 workers are available will grow by 1 in the next turn and decrease the avialalble workers pool by 1
4. Cells with a population of 2, adjacent to at least four cells with a population of at least 2, and 2 workers are available will grow by 1 in the next turn and decrease the avialable workers pool by 1
5. Cells produce pollution equal to their population, and pollution spreads to all adjacent cells as one less than the source
6. Cells provide goods to the Commercial zones equal to their population, but can only be allocated once/ to one zone cell

# Commercial
1. Cells with a population of 0, adjacent to a powerline, there is at least 1 worker available, and at least 1 goods available will grow by 1 in the next turn and decrease the aviable workers and goods pool by 1 each
2. Cells with a population of 0, adjacent to at least one cell with a population of at least 1, there is at least 1 worker available, and at least 1 goods available will grow by 1 in the next turn and decrease the available workers and goods by 1 each
3. Cells with a population of 1, adjacent to at least two cells with a population of at least 1, there is at least 1 worker avialable, and at least 1 goods avialable will grow by 1 in the next turn and decrease the avialable workers and goods by 1 each
