#include <iostream>
#include <algorithm>

struct Rectangle {
    int x, y, width, height;
};

bool isIntersect(const Rectangle& R1, const Rectangle& R2) {
    return !(R1.x >= R2.x + R2.width ||
             R2.x >= R1.x + R1.width ||
             R1.y >= R2.y + R2.height ||
             R2.y >= R1.y + R1.height);
}

Rectangle IntersectingRectangle(const Rectangle& R1, const Rectangle& R2) {
    if (isIntersect(R1, R2)) {
        int intersectX = std::max(R1.x, R2.x);
        int intersectY = std::max(R1.y, R2.y);
        int intersectWidth = std::min(R1.x + R1.width, R2.x + R2.width) - intersectX;
        int intersectHeight = std::min(R1.y + R1.height, R2.y + R2.height) - intersectY;

        return {intersectX, intersectY, intersectWidth, intersectHeight};
    }
    // No intersection case
    return {0, 0, -1, -1};
}

int main() {
    // Test cases
    Rectangle R1 = {0, 0, 3, 3};
    Rectangle R2 = {1, 1, 3, 2};
    Rectangle R3 = {5, 5, 2, 2};

    // Test 1: Intersecting rectangles
    if (isIntersect(R1, R2)) {
        std::cout << "R1 and R2 intersect.\n";
        Rectangle intersect = IntersectingRectangle(R1, R2);
        std::cout << "Intersection Rectangle: (" << intersect.x << ", " << intersect.y << ", " << intersect.width << ", " << intersect.height << ")\n";
    } else {
        std::cout << "R1 and R2 do not intersect.\n";
    }

    // Test 2: Non-intersecting rectangles
    if (isIntersect(R1, R3)) {
        std::cout << "R1 and R3 intersect.\n";
        Rectangle intersect = IntersectingRectangle(R1, R3);
        std::cout << "Intersection Rectangle: (" << intersect.x << ", " << intersect.y << ", " << intersect.width << ", " << intersect.height << ")\n";
    } else {
        std::cout << "R1 and R3 do not intersect.\n";
    }

    return 0;
}
