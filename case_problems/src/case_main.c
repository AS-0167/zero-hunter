#include <stdio.h>
#include <stdlib.h>
#include "../include/problem1.h"
#include "../include/problem2.h"
#include "../include/problem3.h"
#include "../include/problem4.h"
#include "../include/problem5.h"

void print_menu() {
    printf("\n=== Zero Hunter - Case Problems ===\n");
    printf("1. Problem 1 - Computer Graphics (Ray Tracing)\n");
    printf("2. Problem 2 - Machine Learning (Threshold Calibration)\n");
    printf("3. Problem 3 - Networking (Queue Delay Model)\n");
    printf("4. Problem 4 - Cryptography (Key Strength Estimation)\n");
    printf("5. Problem 5 - Robotics (Joint Angle Control)\n");
    printf("6. Run All Case Problems\n");
    printf("0. Exit\n");
}

void run_all_problems() {
    printf("\n=== Running All Case Problems ===\n");
    
    // Problem 1
    printf("\n--- Problem 1: Computer Graphics ---\n");
    solve_problem1_bisection(0, 5, 1e-5, 50);
    solve_problem1_secant(0, 5, 1e-5, 50);
    compare_problem1_methods();
    
    // Problem 2
    printf("\n--- Problem 2: Machine Learning ---\n");
    solve_problem2_fixed_point(1.0, 1e-5, 50);
    solve_problem2_newton(1.0, 1e-5, 50);
    compare_problem2_methods();
    
    // Problem 3
    printf("\n--- Problem 3: Networking ---\n");
    solve_problem3_bisection(0, 100, 1e-5, 50);
    solve_problem3_regula_falsi(0, 100, 1e-5, 50);
    compare_problem3_methods();
    
    // Problem 4
    printf("\n--- Problem 4: Cryptography ---\n");
    solve_problem4_newton(1e5, 1e-5, 50);
    solve_problem4_secant(1e5, 1e7, 1e-5, 50);
    compare_problem4_stopping_criteria();
    
    // Problem 5
    printf("\n--- Problem 5: Robotics ---\n");
    solve_problem5_bisection(0, 1, 1e-5, 50);
    solve_problem5_newton(0.5, 1e-5, 50);
    compare_problem5_methods();
}

int main() {
    int choice;
    
    printf("=== Zero Hunter - Case Problems Demonstrator ===\n");
    
    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 0) break;
        
        switch (choice) {
            case 1:
                solve_problem1_bisection(0, 5, 1e-5, 50);
                solve_problem1_secant(0, 5, 1e-5, 50);
                compare_problem1_methods();
                break;
                
            case 2:
                solve_problem2_fixed_point(1.0, 1e-5, 50);
                solve_problem2_newton(1.0, 1e-5, 50);
                compare_problem2_methods();
                break;
                
            case 3:
                solve_problem3_bisection(0, 100, 1e-5, 50);
                solve_problem3_regula_falsi(0, 100, 1e-5, 50);
                compare_problem3_methods();
                break;
                
            case 4:
                solve_problem4_newton(1e5, 1e-5, 50);
                solve_problem4_secant(1e5, 1e7, 1e-5, 50);
                compare_problem4_stopping_criteria();
                break;
                
            case 5:
                solve_problem5_bisection(0, 1, 1e-5, 50);
                solve_problem5_newton(0.5, 1e-5, 50);
                compare_problem5_methods();
                break;
                
            case 6:
                run_all_problems();
                break;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}