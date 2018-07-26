#include "ddspp.h"

#include <iostream>
#include <cstdio>

int main()
{
	const char* path = "data/white.dds";

	FILE* fh = fopen(path, "rb");

	int ddsSize;
	fseek(fh, 0, SEEK_END);
	ddsSize = ftell(fh);
	rewind(fh);
	
	unsigned char* data = new unsigned char[ddsSize];

	fread(data, sizeof(*data), ddsSize, fh);

	ddspp::Descriptor desc;
	unsigned char* ddsData = ddspp::decode_header(data, desc);

	ddspp::Header h;
	ddspp::HeaderDXT10 h10;
	ddspp::encode_header(desc.format, desc.width, desc.height, desc.depth, desc.type, desc.numMips, desc.arraySize, h, h10);

	unsigned int offset = ddspp::get_offset(desc, 4, 0);

	return 0;
}