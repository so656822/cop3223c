#include <stdio.h>

/* Conversion constants */
const double C_TO_F_SCALE  = 9.0 / 5.0;
const double C_TO_F_OFFSET = 32.0;
const double MI_TO_KM      = 1.60934;
const double LB_TO_KG      = 0.453592;

void convert_temperature(void);
void convert_distance(void);
void convert_weight(void);
void convert_speed(void);

int get_validated_int(int min, int max, const char *prompt, const char *err){
    
    int value;
    int isint;

    do {
        printf("%s", prompt);
        isint = scanf("%d", &value);

        if (isint != 1) {
            printf("\nInput is not an int\n");
            while (getchar() != '\n');
        } 
        
        else if (value < min || value > max) {
            printf("%s\n", err);
            isint = 0;
        }

    } while (isint != 1);

    return value;
};

int main(void) {
    int choice;

    do {
        printf("\n= Unit Conversion Station =\n");
        printf("1. Temperature  (Celsius <-> Fahrenheit)\n");
        printf("2. Distance     (Miles <-> Kilometers)\n");
        printf("3. Weight       (Pounds <-> Kilograms)\n");
        printf("4. Speed        (MPH <-> KPH)\n");
        printf("5. Quit\n");

        choice = get_validated_int(1, 5,
            "Enter choice (1-5): ",
            "Invalid choice. Try again.");

        switch (choice) {
            case 1: convert_temperature(); break;
            case 2: convert_distance();    break;
            case 3: convert_weight();      break;
            case 4: convert_speed();       break;
            case 5: printf("Goodbye!\n");  break;
        }

    } while (choice != 5);

    return 0;
}


void convert_temperature(void) {
    int direction;
    float input;
    float result;

    // Prompt user using get_validated_int function
    direction = get_validated_int(1, 2, "\n--- Temperature ---\n\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\nEnter direction (1-2): ", "Invalid direction. Try again.");

    //C to F case
    if (direction == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &input);
       
        //Calculate value
        result = (input * C_TO_F_SCALE) + C_TO_F_OFFSET;

        //Print Results
        printf("%.2f°C = %.2f°F\n", input, result);
    } 
    
    // F to C case
    else {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &input);

        //Calculate value
        result = (input - C_TO_F_OFFSET) / C_TO_F_SCALE;

        //Print Results
        printf("%.2f° = %.2f°C\n", input, result);
    }
};

void convert_distance(void) {
    int direction;
    float input;
    float result;

    // Prompt user using get_validated_int function
    direction = get_validated_int(1, 2, "\n--- Distance ---\n\n1. Miles to Kilometers\n2. Kilometers to Miles\nEnter direction (1-2): ", "Invalid direction. Try again.");

    // Mi to Km case
    if (direction == 1) {
        printf("Enter distance in miles: ");
        scanf("%f", &input);

        // Calculate value
        result = input * MI_TO_KM;

        // Print Results
        printf("%.2f miles = %.2f km\n", input, result);
    }

    // Km to Mi case
    else {
        printf("Enter distance in Kilometers: ");
        scanf("%f", &input);

        // Calculate value
        result = input / MI_TO_KM;

        // Print Results
        printf("%.2f km = %.2f miles\n", input, result);
    }
};

void convert_weight(void) {
    int direction;
    float input;
    float result;

    // Prompt user using get_validated_int function
    direction = get_validated_int(1, 2, "\n--- Weight ---\n\n1. Pounds to Kilograms\n2. Kilograms to Pounds\nEnter direction (1-2): ", "Invalid direction. Try again.");

    // Lb to Kg case
    if (direction == 1) {
        printf("Enter weight in lbs: ");
        scanf("%f", &input);

        // Calculate value
        result = input * LB_TO_KG;

        // Print Results
        printf("%.2f lbs = %.2f kg\n", input, result);
    }

    // Kg to Lb case
    else {
        printf("Enter weight in Kilograms: ");
        scanf("%f", &input);

        // Calculate value
        result = input / LB_TO_KG;

        // Print Results
        printf("%.2f kg = %.2f lbs\n", input, result);
    }
};

void convert_speed(void) {
    int direction;
    float input;
    float result;

    // Prompt user using get_validated_int function
    direction = get_validated_int(1, 2, "\n--- Speed ---\n\n1. MPH to KPH\n2. KPH to MPH\nEnter direction (1-2): ", "Invalid direction. Try again.");

    // MPH to KPH case
    if (direction == 1) {
        printf("Enter speed in mph: ");
        scanf("%f", &input);

        // Calculate value
        result = input * MI_TO_KM;

        // Print Results
        printf("%.2f mph = %.2f kph\n", input, result);
    }

    // KPH to MPH case
    else {
        printf("Enter speed in kph: ");
        scanf("%f", &input);

        // Calculate value
        result = input / MI_TO_KM;

        // Print Results
        printf("%.2f kph = %.2f mph\n", input, result);
    }
};