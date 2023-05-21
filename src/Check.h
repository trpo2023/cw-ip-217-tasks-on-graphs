#ifndef CHECK_H
#define CHECK_H

bool check_file_exists(const char* filename);
bool check_num_vertices(const char* filename);
bool check_matrix(const char* filename);
bool check_matrix_element(int x, int row, int col);

#endif