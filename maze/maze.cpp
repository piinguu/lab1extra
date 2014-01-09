#include "Matrix.h"


int main()
{
    const char *small[] =
    {"#####################",
     "      # # #   # # # #",
     "##### #     # #   # #",
     "#     ##### # # #   #",
     "### # #   # #   # # #",
     "# # # # # # ####### #",
     "#   #   #   #       #",
     "## ############ #####",
     "#   #                ",
     "#####################",
     0};

    const char *medium[] =
    {"# #######################################",
     "# #                   #     #   #     # #",
     "# # ### ############# # # ### # # ### # #",
     "# #   #     #   #   #   #     # #   # # #",
     "# ### # ### # # # # ##### ####### # # # #",
     "#   # # # #   #   #     #   #   # # # # #",
     "### # # # # ########### ##### # ### # # #",
     "#   # #   #   # #             # #   # # #",
     "# # # ####### # # ############# # ### # #",
     "# # #     #   # #             # #   # # #",
     "# ### ### # ### ############# # ### # # #",
     "#   #   # #   #   #     #   # # #   # # #",
     "### ##### ### ### # # ### # # # # ### # #",
     "#   #     # # #     #     # # # # # #   #",
     "# ### ##### # # ############# # # # # ###",
     "#     #     # #               # # # #   #",
     "####### ##### ################### # # ###",
     "#         #   #     #             # #   #",
     "# ####### # ### # # # ############# ### #",
     "#       #       # #               #     #",
     "####################################### #",
     0};

    const char *large[] =
    {"# ###############################################################################",
        "# #         # #     #       #         #       #   #     #     #   #             #",
        "# ### ##### # # ### # ##### # ##### # # ### ### # # ### ##### # # # # ##### #####",
        "#   # #   # # # # #   #     # #   # #   # #   # # # # #     # # #   # #   # #   #",
        "# # # # # # # # # ### # ##### # # # ##### # # # # # # # ### # # ##### # # ### # #",
        "# #   # #     # # #   #     #   # # #   #   #   # # # # # #   #     #   # #   # #",
        "####### ####### # # ### ######### ### ####### ### # # # # # # ##### ##### # ### #",
        "#   #   #     # # # # #         #   #   #     #   # #   #   #   # #     #   #   #",
        "# # # ### ### # # # # # ####### ### ### # # ### ##### ######### # # ### ##### ###",
        "# #   #   # #   #   # # #     #   # #   # #   #     # #   #   #   # # # #   #   #",
        "# ##### ### # ####### # ##### # # # # ### ######### # ### # # ##### # # # # # ###",
        "#     #     #   #     #     # # #   #     #   #   # #   # # #       # # # # #   #",
        "# ##### # ##### # ######### # ####### ##### # ### # # # # # ######### # ### # # #",
        "#   #   # #   #     #     #   #     #     # #   # # # #   #   #       #     # # #",
        "### # ### # ####### # ### ##### ### ##### # ### # # # ######### # ########### # #",
        "#   # # #       # #   #       #   #     # # # #     # #         #   #     #   # #",
        "# ### # ####### # ##### ######### ##### ### # # ##### # ######### # # ##### # # #",
        "# #   #   #     #       #   #     #   #     # # #   # # #     #   # #   #   # # #",
        "# # ##### # ############# ### ### # # ####### # # # # # ### # # ### ### # ##### #",
        "#   #   # #             #   #   # # # #   #   #   # # # #   # #   # #   # #   # #",
        "##### # # ######### ### ### ### ### # # # # ####### # # # ##### # # # ### # # # #",
        "#   # #           #   #   #   #     #   # #   #       # # #     # # #   # # #   #",
        "# ### ########### ### # ### ### ######### # # ######### # # ##### ### # # # #####",
        "# #   #     #   # #   #   #   # #     #   # #   #     # #   # #   #   # # # #   #",
        "# # ### ### # # # # ##### ### # # ### # ####### # # # # ##### # ### # # # # # ###",
        "# # #     #   #   # #   #     # # #   #         # # # #       #   # # # # #     #",
        "# # # ### ########### # # ##### # ######### ##### # ### ######### # ### # ##### #",
        "#   #   # #       #   #   #     #         #       #     #   #     #   # # #     #",
        "####### # # ##### # ##################### ########### ### # # ####### # # # #####",
        "#     # # # #   #   #     #     #   #   # #     #   # #   # # #       # # #     #",
        "# ### # ### # ####### # # # ### ### # # # # # # # # # # ##### # # ####### #######",
        "# # #       # #       # #   #   #   # # #   # # # # # # #     # #   # #   #     #",
        "# # # ####### # ####### ##### ### ### # ##### # # # ### # ### # # # # # ### ### #",
        "#   # #     # #       # #   #   #     #   # # #   #     #   #   # #   #     # # #",
        "##### # ### # ####### ### # # ########### # # # ### ####### ####### ######### # #",
        "#   #     #         #   # # #       #   # # # # # #   #     #     #   #   #   # #",
        "# ### # ########### ### # # ####### # # # # # # # # # # ##### ### ### # # # ### #",
        "# #   # #   #   #     #   #       #   #     # # # # #   #     #   # # # #     # #",
        "# # ##### ### # ########### ############# ### # # ####### ##### ### # ### # # # #",
        "# #     #   # #     #   #   #     #     #   # # #       # #     #   #     # #   #",
        "# ### # ### # ##### # # # ### ### # ### ##### # # ##### # # ##### ######### #####",
        "#   # #   # # #     # #   #   #   #   #       # #     #   #   #   #   #     #   #",
        "### ##### # # ####### # ### ### ##### ########### ### ####### # ### # ####### # #",
        "#     #   # #       # #   # #   #   #           # #   #       #   # #       # # #",
        "### # # ### ####### # ### # # ### # ########### ### ####### ### # # ####### # # #",
        "#   # # #   #   #   #   #   #   # #   #             #     #   # # #   #   # # # #",
        "# ##### # # # # # ##### # ##### ### # ############### ### ##### # ### # # # ### #",
        "#         # # # # #     # #   # #   #         #     #   #       # #   # # #   # #",
        "# ##### ### # # # # ####### # # # ##### ##### # ##### # ######### # ### # ### # #",
        "# #   #   #   # # #     #   # # # #   # # #   #   #   # # #   #   # #   #   #   #",
        "# # # ######### # ##### # ### # # # # # # # # ### # # # # # ### # ### ##### # ###",
        "# # #   #     # #     # #   # #     # #   # #     # # # # #   # #   #     #     #",
        "### # # # ### # ##### # # # ######### ##### ####### # # # ### # ### ########### #",
        "#   # #   #   #   #   # # #         # #   #   # #   # #   # #   #       #   #   #",
        "# ##### ####### # # ### # ######### # # # ### # # ####### # # ### ####### # # ###",
        "# #   # #     # # #   # #   #   # # # # #   #   # #     # # #   #         # #   #",
        "# # # # # ### # ### # # ### # # # # # # # ### ### # ##### # # # ########### ### #",
        "#   # #   # #   #   # # # # # #   #   # # #   #   #     #   # #   #   #   #     #",
        "##### ##### # ### ### # # # # # ####### # # ### ####### ##### ### # # # #########",
        "#           #       #     #   #         # #           #         #   #           #",
        "############################################################################### #",
        0};
    
    
    Matrix m1;
    m1.read(small);
    m1.solve();
    std::cout << m1 << std::endl;
    
    Matrix m2;
    m2.read(medium);
    m2.solve();
    std::cout << m2 << std::endl;
    
    Matrix m3;
    m3.read(large);
    m3.solve();
    std::cout << m3 << std::endl;
    return 0;
}
