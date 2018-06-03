#include <PNMreader.h>
#include <PNMwriter.h>
#include <filters.h>

int main(int argc, char *argv[])
{
    PNMreader reader(argv[1]);
    PNMreader reader2(argv[2]);

    Subtract single_filter;

    single_filter.SetInput(reader.GetOutput());
    single_filter.SetInput2(reader2.GetOutput());

    single_filter.GetOutput()->Update();

    PNMwriter writer;
    writer.SetInput(single_filter.GetOutput());
    writer.Write(argv[3]);

    CheckSum cs;
    cs.SetInput(single_filter.GetOutput());
    cs.OutputCheckSum("subtract_checksum");
}
