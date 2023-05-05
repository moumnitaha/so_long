/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:12:30 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/05 19:59:47 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>

#define ROWS 5
#define COLS 13

char map[ROWS][COLS + 1] = {
    "1111111111111",
    "10000000000C1",
    "1000111111001",
    "1P0011E000001",
    "1111111111111"
};

struct Position {
    int row;
    int col;
};

int isValid(int row, int col, int visited[][COLS]) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
        return 0;

    if (visited[row][col] || map[row][col] == '1')
        return 0;

    return 1;
}

int findPath(int row, int col, int visited[][COLS]) {
    if (map[row][col] == 'C')
    {
        printf("C: %d , %d\n",row, col);
        return 1;
    }

    visited[row][col] = 1;

    if (isValid(row, col + 1, visited) && findPath(row, col + 1, visited))
    {
        printf("%d , %d\n",row, col + 1);
        return 1;
    }
    if (isValid(row + 1, col, visited) && findPath(row + 1, col, visited))
    {
        printf("%d , %d\n",row + 1, col);
        return 1;
    }

    if (isValid(row, col - 1, visited) && findPath(row, col - 1, visited))
    {
        printf("%d , %d\n",row, col - 1);
        return 1;
    }

    if (isValid(row - 1, col, visited) && findPath(row - 1, col, visited))
    {
        printf("%d , %d\n",row - 1, col);
        return 1;
    }

    visited[row][col] = 0;

    return 0;
}

int main() {
    int startRow, startCol;
    int foundStart = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == 'P') {
                startRow = i;
                startCol = j;
                foundStart = 1;
                break;
            }
        }
        if (foundStart)
            break;
    }

    int visited[ROWS][COLS] = {0};

    if (findPath(startRow, startCol, visited))
        printf("Path found!\n");
    else
        printf("No path found.\n");

    return 0;
}