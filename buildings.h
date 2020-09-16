#define WIDTH_OF_WINDOW 6
#define HEIGHT_OF_WINDOW 10
#define H_SPACE_BETWEEN_WINDOWS 6
#define V_SPACE_BETWEEN_WINDOWS 8
#define FLOOR_HEIGHT 10
#define MIN_WINDOW_PADDING 4

int get_building_color();
int draw_windows_for_building(int left, int width_of_building, int top);
int draw_building(int x, int width_of_building, int height_of_building);
