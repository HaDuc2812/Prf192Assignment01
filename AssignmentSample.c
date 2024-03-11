#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATERIALS 100

struct Material {
    char code[20];
    char name[100];
    char material_type[50];
    char unit[20];
    float price;
};

struct Material materials[MAX_MATERIALS];
int material_count = 0;

void add_material() {
    if(material_count < MAX_MATERIALS) {
        printf("Enter code: ");
        scanf("%s", materials[material_count].code);
        printf("Enter name: ");
        scanf("%s", materials[material_count].name);
        printf("Enter type: ");
        scanf("%s", materials[material_count].material_type);
        printf("Enter unit: ");
        scanf("%s", materials[material_count].unit);
        printf("Enter price: ");
        scanf("%f", &materials[material_count].price);
        material_count++;
        printf("Material added successfully.\n");
    } else {
        printf("Cannot add more materials. Limit reached.\n");
    }
}

void edit_price(char code[20]) {
     int i;
    for(i = 0; i < material_count; i++) {
        if(strcmp(materials[i].code, code) == 0) {
            printf("Enter new price: ");
            scanf("%f", &materials[i].price);
            printf("Price updated successfully.\n");
            return;
        }
    }
    printf("Material not found.\n");
}

void edit_name(char code[20]) {
     int i;
    for(i = 0; i < material_count; i++) {
        if(strcmp(materials[i].code, code) == 0) {
            printf("Enter new name: ");
            scanf("%s", materials[i].name);
            printf("Name updated successfully.\n");
            return;
        }
    }
    printf("Material not found.\n");
}

void delete_material(char code[20]) {
     int i, j;
    for(i = 0; i < material_count; i++) {
        if(strcmp(materials[i].code, code) == 0) {
            for(j = i; j < material_count - 1; j++) {
                materials[j] = materials[j+1];
            }
            material_count--;
            printf("Material deleted successfully.\n");
            return;
        }
    }
    printf("Material not found.\n");
}

void sort_by_material_type_descending() {
    struct Material temp;
    int i, j;
    for(i = 0; i < material_count - 1; i++) {
        for(j = i + 1; j < material_count; j++) {
            if(strcmp(materials[i].material_type, materials[j].material_type) < 0) {
                temp = materials[i];
                materials[i] = materials[j];
                materials[j] = temp;
            }
        }
    }
    printf("Materials sorted by material type (descending).\n");
}

void sort_by_price_ascending() {
    struct Material temp;
    int i, j;
    for(i = 0; i < material_count - 1; i++) {
        for(j = i + 1; j < material_count; j++) {
            if(materials[i].price > materials[j].price) {
                temp = materials[i];
                materials[i] = materials[j];
                materials[j] = temp;
            }
        }
    }
    printf("Materials sorted by price (ascending).\n");
}

void display_all_materials() {
    printf("=== All Materials ===\n");
    int i;
    for(i = 0; i < material_count; i++) {
        printf("Code: %s\n", materials[i].code);
        printf("Name: %s\n", materials[i].name);
        printf("Type: %s\n", materials[i].material_type);
        printf("Unit: %s\n", materials[i].unit);
        printf("Price: %.2f\n", materials[i].price);
        printf("\n");
    }
}

void display_material_by_code(char code[20]) {
     int i;
    for(i = 0; i < material_count; i++) {
        if(strcmp(materials[i].code, code) == 0) {
            printf("Code: %s\n", materials[i].code);
            printf("Name: %s\n", materials[i].name);
            printf("Type: %s\n", materials[i].material_type);
            printf("Unit: %s\n", materials[i].unit);
            printf("Price: %.2f\n", materials[i].price);
            return;
        }
    }
    printf("Material not found.\n");
}

void display_materials_in_price_range(float min_price, float max_price) {
     int i;
    printf("=== Materials in Price Range %.2f to %.2f ===\n", min_price, max_price);
    for(i = 0; i < material_count; i++) {
        if(materials[i].price >= min_price && materials[i].price <= max_price) {
            printf("Code: %s\n", materials[i].code);
            printf("Name: %s\n", materials[i].name);
            printf("Type: %s\n", materials[i].material_type);
            printf("Unit: %s\n", materials[i].unit);
            printf("Price: %.2f\n", materials[i].price);
            printf("\n");
        }
    }
}

void display_statistics() {
     int i;
    float total_price = 0;
    float avg_price;
    float max_price = materials[0].price;
    float min_price = materials[0].price;
    for(i = 0; i < material_count; i++) {
        total_price += materials[i].price;
        if(materials[i].price > max_price) {
            max_price = materials[i].price;
        }
        if(materials[i].price < min_price) {
            min_price = materials[i].price;
        }
    }
    avg_price = total_price / material_count;
    printf("Average Price: %.2f\n", avg_price);
    printf("Max Price: %.2f\n", max_price);
    printf("Min Price: %.2f\n", min_price);
}

int main() {
    int choice;
    char code[20];
    float min_price, max_price;
    while(1) {
        printf("\n=== Material Management System ===\n");
        printf("1. Add Material\n");
        printf("2. Edit Price\n");
        printf("3. Edit Name\n");
        printf("4. Delete Material\n");
        printf("5. Sort by Material Type (Descending)\n");
        printf("6. Sort by Price (Ascending)\n");
        printf("7. Display All Materials\n");
        printf("8. Display Material by Code\n");
        printf("9. Display Materials in Price Range\n");
        printf("10. Display Statistics\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_material();
                break;
            case 2:
                printf("Enter code of material to edit price: ");
                scanf("%s", code);
                edit_price(code);
                break;
            case 3:
                printf("Enter code of material to edit name: ");
                scanf("%s", code);
                edit_name(code);
                break;
            case 4:
                printf("Enter code of material to delete: ");
                scanf("%s", code);
                delete_material(code);
                break;
            case 5:
                sort_by_material_type_descending();
                break;
            case 6:
                sort_by_price_ascending();
                break;
            case 7:
                display_all_materials();
                break;
            case 8:
                printf("Enter code of material to display: ");
                scanf("%s", code);
                display_material_by_code(code);
                break;
            case 9:
                printf("Enter minimum price: ");
                scanf("%f", &min_price);
                printf("Enter maximum price: ");
                scanf("%f", &max_price);
                display_materials_in_price_range(min_price, max_price);
                break;
            case 10:
                display_statistics();
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
