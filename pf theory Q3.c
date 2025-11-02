#include <stdio.h>
#define ROWS 3
#define COLS 3
void updateSector(int grid[ROWS][COLS]);
void querySector(int grid[ROWS][COLS]);
void runDiagnostic(int grid[ROWS][COLS]);
int main() {
    int grid[ROWS][COLS] = {0}; 
    int choice = 0;
    while (choice != 4) {
        printf("\n--- IESCO GRID MONITORING SYSTEM ---\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                updateSector(grid);
                break;
            case 2:
                querySector(grid);
                break;
            case 3:
                runDiagnostic(grid);
                break;
            case 4:
                printf("\nExiting system... Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}
void updateSector(int grid[ROWS][COLS]) {
    int row, col, flag, action;
    printf("\nEnter sector coordinates (row and column 0-%d): ", ROWS - 1);
    scanf("%d%d", &row, &col);
    if (row >= ROWS || col >= COLS || row < 0 || col < 0) {
        printf("Invalid coordinates!\n");
        return;
    }
    printf("Select status flag to update:\n");
    printf("0 - Power Status (ON/OFF)\n");
    printf("1 - Overload Warning\n");
    printf("2 - Maintenance Required\n");
    printf("Enter flag number: ");
    scanf("%d", &flag);
    if (flag < 0 || flag > 2) {
        printf("Invalid flag!\n");
        return;
    }
    printf("Enter action (1 to SET, 0 to CLEAR): ");
    scanf("%d", &action);
    if (action == 1) {
        grid[row][col] = grid[row][col] | (1 << flag);   
        printf("Flag %d set successfully.\n", flag);
    } else {
        grid[row][col] = grid[row][col] & ~(1 << flag); 
        printf("Flag %d cleared successfully.\n", flag);
    }
}
void querySector(int grid[ROWS][COLS]) {
    int row, col;
    printf("\nEnter sector coordinates (row and column 0-%d): ", ROWS - 1);
    scanf("%d%d", &row, &col);

    if (row >= ROWS || col >= COLS || row < 0 || col < 0) {
        printf("Invalid coordinates!\n");
        return;
    }
    int status = grid[row][col];
    printf("\nSector [%d][%d] Status Report:\n", row, col);
    printf("Power: %s\n", (status & 1) ? "ON" : "OFF");
    printf("Overload: %s\n", (status & 2) ? "YES" : "NO");
    printf("Maintenance Required: %s\n", (status & 4) ? "YES" : "NO");
}
void runDiagnostic(int grid[ROWS][COLS]) {
    int i,j,overloadCount = 0, maintenanceCount = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] & 2) 
                overloadCount++;
            if (grid[i][j] & 4)
                maintenanceCount++;
        }
    }
    printf("\n--- System Diagnostic Report ---\n");
    printf("Total Overloaded Sectors: %d\n", overloadCount);
    printf("Total Maintenance Required: %d\n", maintenanceCount);
}

