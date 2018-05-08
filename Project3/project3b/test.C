#include <image.h>
#include <functions.h>

int main(int argc, char *argv[])
{
    Image img;

    ReadImage(argv[1], img);
    // HalfSize(img4, img5);
    WriteImage(argv[2], img);
}
