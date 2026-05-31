#pragma once

// Sources
// https://learn.microsoft.com/en-us/windows/uwp/gaming/complete-code-for-ddstextureloader
// https://learn.microsoft.com/en-us/windows/win32/direct3ddds/dds-header
// https://learn.microsoft.com/en-us/windows/win32/direct3ddds/dds-header-dxt10
// https://learn.microsoft.com/en-us/windows/win32/direct3ddds/dds-pixelformat

#if (__cpp_constexpr >= 201304) || (_MSC_VER > 1900)
#define ddspp_constexpr constexpr
#else
#define ddspp_constexpr const
#endif

#if defined(_MSC_VER)

	#define ddspp_warning_underlying_enum_type_begin \
		__pragma(warning(push)) \
		__pragma(warning(disable : 4480))
		
	#define ddspp_warning_underlying_enum_type_end __pragma(warning(pop))

#else
	#define ddspp_warning_underlying_enum_type_begin
	#define ddspp_warning_underlying_enum_type_end
#endif

ddspp_warning_underlying_enum_type_begin

namespace ddspp
{
	namespace internal
	{
		static ddspp_constexpr unsigned int DDS_MAGIC      = 0x20534444;

		static ddspp_constexpr unsigned int DDS_ALPHAPIXELS       = 0x00000001; // DDPF_ALPHAPIXELS
		static ddspp_constexpr unsigned int DDS_ALPHA             = 0x00000002; // DDPF_ALPHA
		static ddspp_constexpr unsigned int DDS_FOURCC            = 0x00000004; // DDPF_FOURCC
		static ddspp_constexpr unsigned int DDS_PALETTEINDEXED4   = 0x00000008; // DDPF_PALETTEINDEXED4
		static ddspp_constexpr unsigned int DDS_PALETTEINDEXEDTO8 = 0x00000010; // DDPF_PALETTEINDEXEDTO8
		static ddspp_constexpr unsigned int DDS_PALETTEINDEXED8   = 0x00000020; // DDPF_PALETTEINDEXED8
		static ddspp_constexpr unsigned int DDS_RGB               = 0x00000040; // DDPF_RGB
		static ddspp_constexpr unsigned int DDS_COMPRESSED        = 0x00000080; // DDPF_COMPRESSED
		static ddspp_constexpr unsigned int DDS_RGBTOYUV          = 0x00000100; // DDPF_RGBTOYUV
		static ddspp_constexpr unsigned int DDS_YUV               = 0x00000200; // DDPF_YUV
		static ddspp_constexpr unsigned int DDS_ZBUFFER           = 0x00000400; // DDPF_ZBUFFER
		static ddspp_constexpr unsigned int DDS_PALETTEINDEXED1   = 0x00000800; // DDPF_PALETTEINDEXED1
		static ddspp_constexpr unsigned int DDS_PALETTEINDEXED2   = 0x00001000; // DDPF_PALETTEINDEXED2
		static ddspp_constexpr unsigned int DDS_ZPIXELS           = 0x00002000; // DDPF_ZPIXELS
		static ddspp_constexpr unsigned int DDS_STENCILBUFFER     = 0x00004000; // DDPF_STENCILBUFFER
		static ddspp_constexpr unsigned int DDS_ALPHAPREMULT      = 0x00008000; // DDPF_ALPHAPREMULT
		static ddspp_constexpr unsigned int DDS_LUMINANCE         = 0x00020000; // DDPF_LUMINANCE
		static ddspp_constexpr unsigned int DDS_BUMPLUMINANCE     = 0x00040000; // DDPF_BUMPLUMINANCE
		static ddspp_constexpr unsigned int DDS_BUMPDUDV          = 0x00080000; // DDPF_BUMPDUDV
		
		// Composite flags
		static ddspp_constexpr unsigned int DDS_RGBA              = DDS_RGB | DDS_ALPHA;
		static ddspp_constexpr unsigned int DDS_PALETTEINDEXED8A  = DDS_PALETTEINDEXED8 | DDS_ALPHAPIXELS;
		static ddspp_constexpr unsigned int DDS_LUMINANCEA        = DDS_LUMINANCE | DDS_ALPHAPIXELS;
		static ddspp_constexpr unsigned int DDS_BUMPDUDVA         = DDS_BUMPDUDV | DDS_ALPHAPIXELS;

		static ddspp_constexpr unsigned int DDS_HEADER_FLAGS_CAPS        = 0x00000001; // DDSD_CAPS
		static ddspp_constexpr unsigned int DDS_HEADER_FLAGS_HEIGHT      = 0x00000002; // DDSD_HEIGHT
		static ddspp_constexpr unsigned int DDS_HEADER_FLAGS_WIDTH       = 0x00000004; // DDSD_WIDTH
		static ddspp_constexpr unsigned int DDS_HEADER_FLAGS_PITCH       = 0x00000008; // DDSD_PITCH
		static ddspp_constexpr unsigned int DDS_HEADER_FLAGS_PIXELFORMAT = 0x00001000; // DDSD_PIXELFORMAT
		static ddspp_constexpr unsigned int DDS_HEADER_FLAGS_MIPMAP      = 0x00020000; // DDSD_MIPMAPCOUNT
		static ddspp_constexpr unsigned int DDS_HEADER_FLAGS_LINEARSIZE  = 0x00080000; // DDSD_LINEARSIZE
		static ddspp_constexpr unsigned int DDS_HEADER_FLAGS_VOLUME      = 0x00800000; // DDSD_DEPTH

		static ddspp_constexpr unsigned int DDS_HEADER_CAPS_COMPLEX      = 0x00000008; // DDSCAPS_COMPLEX
		static ddspp_constexpr unsigned int DDS_HEADER_CAPS_MIPMAP       = 0x00400000; // DDSCAPS_MIPMAP
		static ddspp_constexpr unsigned int DDS_HEADER_CAPS_TEXTURE      = 0x00001000; // DDSCAPS_TEXTURE

		static ddspp_constexpr unsigned int DDS_HEADER_CAPS2_CUBEMAP           = 0x00000200; // DDSCAPS2_CUBEMAP
		static ddspp_constexpr unsigned int DDS_HEADER_CAPS2_CUBEMAP_POSITIVEX = 0x00000600; // DDSCAPS2_CUBEMAP | DDSCAPS2_CUBEMAP_POSITIVEX
		static ddspp_constexpr unsigned int DDS_HEADER_CAPS2_CUBEMAP_NEGATIVEX = 0x00000a00; // DDSCAPS2_CUBEMAP | DDSCAPS2_CUBEMAP_NEGATIVEX
		static ddspp_constexpr unsigned int DDS_HEADER_CAPS2_CUBEMAP_POSITIVEY = 0x00001200; // DDSCAPS2_CUBEMAP | DDSCAPS2_CUBEMAP_POSITIVEY
		static ddspp_constexpr unsigned int DDS_HEADER_CAPS2_CUBEMAP_NEGATIVEY = 0x00002200; // DDSCAPS2_CUBEMAP | DDSCAPS2_CUBEMAP_NEGATIVEY
		static ddspp_constexpr unsigned int DDS_HEADER_CAPS2_CUBEMAP_POSITIVEZ = 0x00004200; // DDSCAPS2_CUBEMAP | DDSCAPS2_CUBEMAP_POSITIVEZ
		static ddspp_constexpr unsigned int DDS_HEADER_CAPS2_CUBEMAP_NEGATIVEZ = 0x00008200; // DDSCAPS2_CUBEMAP | DDSCAPS2_CUBEMAP_NEGATIVEZ
		static ddspp_constexpr unsigned int DDS_HEADER_CAPS2_VOLUME            = 0x00200000; // DDSCAPS2_VOLUME
		static ddspp_constexpr unsigned int DDS_HEADER_CAPS2_CUBEMAP_ALLFACES  = 
			DDS_HEADER_CAPS2_CUBEMAP_POSITIVEX | DDS_HEADER_CAPS2_CUBEMAP_NEGATIVEX | DDS_HEADER_CAPS2_CUBEMAP_POSITIVEY | 
			DDS_HEADER_CAPS2_CUBEMAP_NEGATIVEY | DDS_HEADER_CAPS2_CUBEMAP_POSITIVEZ | DDS_HEADER_CAPS2_CUBEMAP_NEGATIVEZ;

		static ddspp_constexpr unsigned int DXGI_MISC_FLAG_CUBEMAP = 0x4; // https://learn.microsoft.com/en-us/windows/win32/api/d3d11/ne-d3d11-d3d11_resource_misc_flag
		static ddspp_constexpr unsigned int DDS_MISC_FLAGS2_ALPHA_MODE_MASK = 0x7;

		enum DXGIAlphaMode : unsigned int
		{
			DDS_ALPHA_MODE_UNKNOWN       = 0,
			DDS_ALPHA_MODE_STRAIGHT      = 1,
			DDS_ALPHA_MODE_PREMULTIPLIED = 2,
			DDS_ALPHA_MODE_OPAQUE        = 3,
			DDS_ALPHA_MODE_CUSTOM        = 4
		};

		#define ddspp_make_fourcc(a, b, c, d) ((a) + ((b) << 8) + ((c) << 16) + ((d) << 24))

		namespace FourCC
		{
			enum T : unsigned int
			{
				DXT1 = ddspp_make_fourcc('D', 'X', 'T', '1'), // BC1_UNORM
				DXT2 = ddspp_make_fourcc('D', 'X', 'T', '2'), // BC2_UNORM
				DXT3 = ddspp_make_fourcc('D', 'X', 'T', '3'), // BC2_UNORM
				DXT4 = ddspp_make_fourcc('D', 'X', 'T', '4'), // BC3_UNORM
				DXT5 = ddspp_make_fourcc('D', 'X', 'T', '5'), // BC3_UNORM
				ATI1 = ddspp_make_fourcc('A', 'T', 'I', '1'), // BC4_UNORM
				BC4U = ddspp_make_fourcc('B', 'C', '4', 'U'), // BC4_UNORM
				BC4S = ddspp_make_fourcc('B', 'C', '4', 'S'), // BC4_SNORM
				ATI2 = ddspp_make_fourcc('A', 'T', 'I', '2'), // BC5_UNORM with R and G swapped
				BC5U = ddspp_make_fourcc('B', 'C', '5', 'U'), // BC5_UNORM
				BC5S = ddspp_make_fourcc('B', 'C', '5', 'S'), // BC5_SNORM
				BC6H = ddspp_make_fourcc('B', 'C', '6', 'H'), // BC6H_UF16

				BC7L = ddspp_make_fourcc('B', 'C', '7', 'L'), // BC7_UNORM
				BC70 = ddspp_make_fourcc('B', 'C', '7', '0'), // BC7_UNORM
				ZOLA = ddspp_make_fourcc('Z', 'O', 'L', 'A'), // BC7_UNORM Old versions of NVTT can produce 'ZOLA'

				RGBG = ddspp_make_fourcc('R', 'G', 'B', 'G'), // R8G8_B8G8_UNORM
				GRGB = ddspp_make_fourcc('G', 'R', 'G', 'B'), // G8R8_G8B8_UNORM
				YUY2 = ddspp_make_fourcc('Y', 'U', 'Y', '2'), // YUY2
				UYVY = ddspp_make_fourcc('U', 'Y', 'V', 'Y'), // UYVY
				DX10 = ddspp_make_fourcc('D', 'X', '1', '0'), // DDS extension header

				R8G8B8        = 20,
				A8R8G8B8      = 21,
				X8R8G8B8      = 22,
				R5G6B5        = 23,
				X1R5G5B5      = 24,
				A1R5G5B5      = 25,
				A4R4G4B4      = 26,
				R3G3B2        = 27,
				A8            = 28,
				A8R3G3B2      = 29,
				X4R4G4B4      = 30,
				A2B10G10R10   = 31,
				A8B8G8R8      = 32,
				X8B8G8R8      = 33,
				G16R16        = 34,
				A2R10G10B10   = 35,
				A16B16G16R16  = 36,

				L8            = 50,
				A8L8          = 51,
				A4L4          = 52,

				V8U8          = 60,
				L6V5U5        = 61,
				X8L8V8U8      = 62,
				Q8W8V8U8      = 63,
				V16U16        = 64,

				A2W10V10U10   = 67,

				L16           = 81,

				Q16W16V16U16  = 110,
				R16F          = 111,
				R16G16F       = 112,
				A16B16G16R16F = 113,
				R32F          = 114,
				R32G32F       = 115,
				A32B32G32R32F = 116,
			};
		};

		struct PixelFormat
		{
			unsigned int size;
			unsigned int flags;
			FourCC::T fourCC;
			unsigned int RGBBitCount;
			unsigned int RBitMask;
			unsigned int GBitMask;
			unsigned int BBitMask;
			unsigned int ABitMask;
		};

		static ddspp_constexpr PixelFormat PF_DXT1          = { 32, DDS_FOURCC,        FourCC::DXT1, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_DXT2          = { 32, DDS_FOURCC,        FourCC::DXT2, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_DXT3          = { 32, DDS_FOURCC,        FourCC::DXT3, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_DXT4          = { 32, DDS_FOURCC,        FourCC::DXT4, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_DXT5          = { 32, DDS_FOURCC,        FourCC::DXT5, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_ATI1          = { 32, DDS_FOURCC,        FourCC::ATI1, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_BC4U          = { 32, DDS_FOURCC,        FourCC::BC4U, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_BC4S          = { 32, DDS_FOURCC,        FourCC::BC4S, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_ATI2          = { 32, DDS_FOURCC,        FourCC::ATI2, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_BC5U          = { 32, DDS_FOURCC,        FourCC::BC5U, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_BC5S          = { 32, DDS_FOURCC,        FourCC::BC5S, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_BC6H          = { 32, DDS_FOURCC,        FourCC::BC6H, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_BC7L          = { 32, DDS_FOURCC,        FourCC::BC7L, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_BC70          = { 32, DDS_FOURCC,        FourCC::BC70, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_ZOLA          = { 32, DDS_FOURCC,        FourCC::ZOLA, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_RGBG          = { 32, DDS_FOURCC,        FourCC::RGBG, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_GRBG          = { 32, DDS_FOURCC,        FourCC::GRGB, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_YUY2          = { 32, DDS_FOURCC,        FourCC::YUY2, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_UYVY          = { 32, DDS_FOURCC,        FourCC::UYVY, 0, 0, 0, 0, 0 };
		static ddspp_constexpr PixelFormat PF_DXT10         = { 32, DDS_FOURCC,        FourCC::DX10, 0, 0, 0, 0, 0 };

		// The FOURCC codes come from the original D3D9 D3DFORMAT values https://learn.microsoft.com/en-us/windows/win32/direct3d9/d3dformat
		static ddspp_constexpr PixelFormat PF_R8G8B8        = { 32, DDS_RGB,           FourCC::R8G8B8,         24, 0x00ff0000, 0x0000ff00, 0x000000ff, 0x00000000 };
		static ddspp_constexpr PixelFormat PF_A8R8G8B8      = { 32, DDS_RGBA,          FourCC::A8R8G8B8,       32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000 };
		static ddspp_constexpr PixelFormat PF_X8R8G8B8      = { 32, DDS_RGB,           FourCC::X8R8G8B8,       24, 0x00ff0000, 0x0000ff00, 0x000000ff, 0x00000000 };
		static ddspp_constexpr PixelFormat PF_R5G6B5        = { 32, DDS_RGB,           FourCC::R5G6B5,         16, 0x0000f800, 0x000007e0, 0x0000001f, 0x00000000 }; // B5G6R5_UNORM   (needs swizzling)
		static ddspp_constexpr PixelFormat PF_X1R5G5B5      = { 32, DDS_RGB,           FourCC::X1R5G5B5,       16, 0x00007c00, 0x000003e0, 0x0000001f, 0x00000000 };
		static ddspp_constexpr PixelFormat PF_A1R5G5B5      = { 32, DDS_RGBA,          FourCC::A1R5G5B5,       16, 0x00007c00, 0x000003e0, 0x0000001f, 0x00008000 }; // B5G5R5A1_UNORM (needs swizzling)
		static ddspp_constexpr PixelFormat PF_A4R4G4B4      = { 32, DDS_RGBA,          FourCC::A4R4G4B4,       16, 0x00000f00, 0x000000f0, 0x0000000f, 0x0000f000 }; // B4G4R4A4_UNORM (needs swizzling)
		static ddspp_constexpr PixelFormat PF_R3G3B2        = { 32, DDS_RGB,           FourCC::R3G3B2,          8, 0x000000e0, 0x0000001c, 0x00000003, 0x00000000 };
		static ddspp_constexpr PixelFormat PF_A8            = { 32, DDS_ALPHA,         FourCC::A8,              8, 0x00000000, 0x00000000, 0x00000000, 0x000000ff };
		static ddspp_constexpr PixelFormat PF_A8R3G3B2      = { 32, DDS_RGBA,          FourCC::A8R3G3B2,       16, 0x000000e0, 0x0000001c, 0x00000003, 0x0000ff00 };
		static ddspp_constexpr PixelFormat PF_X4R4G4B4      = { 32, DDS_RGB,           FourCC::X4R4G4B4,       16, 0x00000f00, 0x000000f0, 0x0000000f, 0x00000000 };
		static ddspp_constexpr PixelFormat PF_A2B10G10R10   = { 32, DDS_RGBA,          FourCC::A2B10G10R10,    32, 0x000003ff, 0x000ffc00, 0x3ff00000, 0xc0000000 };
		static ddspp_constexpr PixelFormat PF_A8B8G8R8      = { 32, DDS_RGBA,          FourCC::A8B8G8R8,       32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000 };
		static ddspp_constexpr PixelFormat PF_X8B8G8R8      = { 32, DDS_RGB,           FourCC::X8B8G8R8,       24, 0x000000ff, 0x0000ff00, 0x00ff0000, 0x00000000 };
		static ddspp_constexpr PixelFormat PF_G16R16        = { 32, DDS_RGB,           FourCC::G16R16,         32, 0x0000ffff, 0xffff0000, 0x00000000, 0x00000000 };
		static ddspp_constexpr PixelFormat PF_A2R10G10B10   = { 32, DDS_RGBA,          FourCC::A2R10G10B10,    32, 0x3ff00000, 0x000ffc00, 0x000003ff, 0xc0000000 };
		static ddspp_constexpr PixelFormat PF_A16B16G16R16  = { 32, DDS_RGBA,          FourCC::A16B16G16R16,   64, 0, 0, 0, 0 }; // R16G16B16A16_UNORM

		static ddspp_constexpr PixelFormat PF_L8            = { 32, DDS_LUMINANCE,     FourCC::L8  ,            8, 0x000000ff, 0x00000000, 0x00000000, 0x00000000 }; // R8_UNORM
		static ddspp_constexpr PixelFormat PF_A8L8          = { 32, DDS_LUMINANCEA,    FourCC::A8L8,           16, 0x000000ff, 0x00000000, 0x00000000, 0x0000ff00 }; // R8G8_UNORM
		static ddspp_constexpr PixelFormat PF_A4L4          = { 32, DDS_LUMINANCEA,    FourCC::A4L4,           16, 0x0000000f, 0x00000000, 0x00000000, 0x000000f0 };

		static ddspp_constexpr PixelFormat PF_V8U8          = { 32, DDS_BUMPDUDV,      FourCC::V8U8,           16, 0x000000ff, 0x0000ff00, 0x00000000, 0x00000000 };
		static ddspp_constexpr PixelFormat PF_L6V5U5        = { 32, DDS_BUMPLUMINANCE, FourCC::L6V5U5,         16, 0x0000001f, 0x000003e0, 0x0000fc00, 0x00000000 };
		static ddspp_constexpr PixelFormat PF_X8L8V8U8      = { 32, DDS_BUMPLUMINANCE, FourCC::X8L8V8U8,       24, 0x000000ff, 0x0000ff00, 0x00ff0000, 0x00000000 };
		static ddspp_constexpr PixelFormat PF_Q8W8V8U8      = { 32, DDS_BUMPDUDV,      FourCC::Q8W8V8U8,       32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000 };
		static ddspp_constexpr PixelFormat PF_V16U16        = { 32, DDS_BUMPDUDV,      FourCC::V16U16,         32, 0x0000ffff, 0xffff0000, 0x00000000, 0x00000000 };

		static ddspp_constexpr PixelFormat PF_A2W10V10U10   = { 32, DDS_BUMPDUDVA,     FourCC::A2W10V10U10,    32, 0x000003ff, 0x000ffc00, 0x3ff00000, 0xc0000000 };

		static ddspp_constexpr PixelFormat PF_L16           = { 32, DDS_LUMINANCE,     FourCC::L16,            16, 0x0000ffff, 0x00000000, 0x00000000, 0x00000000 }; // R16_UNORM

		static ddspp_constexpr PixelFormat PF_Q16W16V16U16  = { 32, DDS_RGBA,          FourCC::Q16W16V16U16,   64, 0, 0, 0, 0 }; // R16G16B16A16_SNORM
		static ddspp_constexpr PixelFormat PF_R16F          = { 32, DDS_RGB,           FourCC::R16F,           16, 0, 0, 0, 0 }; // R16_FLOAT
		static ddspp_constexpr PixelFormat PF_R16G16F       = { 32, DDS_RGB,           FourCC::R16G16F,        32, 0, 0, 0, 0 }; // R16G16_FLOAT
		static ddspp_constexpr PixelFormat PF_A16B16G16R16F = { 32, DDS_RGBA,          FourCC::A16B16G16R16F,  64, 0, 0, 0, 0 }; // R16G16B16A16_FLOAT
		static ddspp_constexpr PixelFormat PF_R32F          = { 32, DDS_RGB,           FourCC::R32F,           32, 0, 0, 0, 0 }; // R32_FLOAT
		static ddspp_constexpr PixelFormat PF_R32G32F       = { 32, DDS_RGB,           FourCC::R32G32F,        64, 0, 0, 0, 0 }; // R32G32_FLOAT
		static ddspp_constexpr PixelFormat PF_A32B32G32R32F = { 32, DDS_RGBA,          FourCC::A32B32G32R32F, 128, 0, 0, 0, 0 }; // R32G32B32A32_FLOAT

		static_assert(sizeof(PixelFormat) == 32, "PixelFormat size mismatch");

		inline ddspp_constexpr bool is_rgba_mask(const PixelFormat& ddspf, const PixelFormat& other)
		{
			return (ddspf.RBitMask == other.RBitMask) && (ddspf.GBitMask == other.GBitMask) && (ddspf.BBitMask == other.BBitMask) && (ddspf.ABitMask == other.ABitMask);
		}
	}

	using namespace internal;

	// https://docs.microsoft.com/en-us/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_dimension
	enum DXGIResourceDimension : unsigned int
	{
		DXGI_Unknown   = 0,
		DXGI_Buffer    = 1,
		DXGI_Texture1D = 2,
		DXGI_Texture2D = 3,
		DXGI_Texture3D = 4
	};

	// Matches DXGI_FORMAT https://docs.microsoft.com/en-us/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format
	enum DXGIFormat : unsigned int
	{
		UNKNOWN	                    = 0,
		R32G32B32A32_TYPELESS       = 1,
		R32G32B32A32_FLOAT          = 2,
		R32G32B32A32_UINT           = 3,
		R32G32B32A32_SINT           = 4,
		R32G32B32_TYPELESS          = 5,
		R32G32B32_FLOAT             = 6,
		R32G32B32_UINT              = 7,
		R32G32B32_SINT              = 8,
		R16G16B16A16_TYPELESS       = 9,
		R16G16B16A16_FLOAT          = 10,
		R16G16B16A16_UNORM          = 11,
		R16G16B16A16_UINT           = 12,
		R16G16B16A16_SNORM          = 13,
		R16G16B16A16_SINT           = 14,
		R32G32_TYPELESS             = 15,
		R32G32_FLOAT                = 16,
		R32G32_UINT                 = 17,
		R32G32_SINT                 = 18,
		R32G8X24_TYPELESS           = 19,
		D32_FLOAT_S8X24_UINT        = 20,
		R32_FLOAT_X8X24_TYPELESS    = 21,
		X32_TYPELESS_G8X24_UINT     = 22,
		R10G10B10A2_TYPELESS        = 23,
		R10G10B10A2_UNORM           = 24,
		R10G10B10A2_UINT            = 25,
		R11G11B10_FLOAT             = 26,
		R8G8B8A8_TYPELESS           = 27,
		R8G8B8A8_UNORM              = 28,
		R8G8B8A8_UNORM_SRGB         = 29,
		R8G8B8A8_UINT               = 30,
		R8G8B8A8_SNORM              = 31,
		R8G8B8A8_SINT               = 32,
		R16G16_TYPELESS             = 33,
		R16G16_FLOAT                = 34,
		R16G16_UNORM                = 35,
		R16G16_UINT                 = 36,
		R16G16_SNORM                = 37,
		R16G16_SINT                 = 38,
		R32_TYPELESS                = 39,
		D32_FLOAT                   = 40,
		R32_FLOAT                   = 41,
		R32_UINT                    = 42,
		R32_SINT                    = 43,
		R24G8_TYPELESS              = 44,
		D24_UNORM_S8_UINT           = 45,
		R24_UNORM_X8_TYPELESS       = 46,
		X24_TYPELESS_G8_UINT        = 47,
		R8G8_TYPELESS               = 48,
		R8G8_UNORM                  = 49,
		R8G8_UINT                   = 50,
		R8G8_SNORM                  = 51,
		R8G8_SINT                   = 52,
		R16_TYPELESS                = 53,
		R16_FLOAT                   = 54,
		D16_UNORM                   = 55,
		R16_UNORM                   = 56,
		R16_UINT                    = 57,
		R16_SNORM                   = 58,
		R16_SINT                    = 59,
		R8_TYPELESS                 = 60,
		R8_UNORM                    = 61,
		R8_UINT                     = 62,
		R8_SNORM                    = 63,
		R8_SINT                     = 64,
		A8_UNORM                    = 65,
		R1_UNORM                    = 66,
		R9G9B9E5_SHAREDEXP          = 67,
		R8G8_B8G8_UNORM             = 68,
		G8R8_G8B8_UNORM             = 69,
		BC1_TYPELESS                = 70,
		BC1_UNORM                   = 71,
		BC1_UNORM_SRGB              = 72,
		BC2_TYPELESS                = 73,
		BC2_UNORM                   = 74,
		BC2_UNORM_SRGB              = 75,
		BC3_TYPELESS                = 76,
		BC3_UNORM                   = 77,
		BC3_UNORM_SRGB              = 78,
		BC4_TYPELESS                = 79,
		BC4_UNORM                   = 80,
		BC4_SNORM                   = 81,
		BC5_TYPELESS                = 82,
		BC5_UNORM                   = 83,
		BC5_SNORM                   = 84,
		B5G6R5_UNORM                = 85,
		B5G5R5A1_UNORM              = 86,
		B8G8R8A8_UNORM              = 87,
		B8G8R8X8_UNORM              = 88,
		R10G10B10_XR_BIAS_A2_UNORM  = 89,
		B8G8R8A8_TYPELESS           = 90,
		B8G8R8A8_UNORM_SRGB         = 91,
		B8G8R8X8_TYPELESS           = 92,
		B8G8R8X8_UNORM_SRGB         = 93,
		BC6H_TYPELESS               = 94,
		BC6H_UF16                   = 95,
		BC6H_SF16                   = 96,
		BC7_TYPELESS                = 97,
		BC7_UNORM                   = 98,
		BC7_UNORM_SRGB              = 99,
		AYUV                        = 100,
		Y410                        = 101,
		Y416                        = 102,
		NV12                        = 103,
		P010                        = 104,
		P016                        = 105,
		OPAQUE_420                  = 106,
		YUY2                        = 107,
		Y210                        = 108,
		Y216                        = 109,
		NV11                        = 110,
		AI44                        = 111,
		IA44                        = 112,
		P8                          = 113,
		A8P8                        = 114,
		B4G4R4A4_UNORM              = 115,

		// Xbox-specific
		R10G10B10_7E3_A2_FLOAT      = 116,
		R10G10B10_6E4_A2_FLOAT      = 117,
		D16_UNORM_S8_UINT           = 118,
		R16_UNORM_X8_TYPELESS       = 119,
		X16_TYPELESS_G8_UINT        = 120,
		
		P208                        = 130,
		V208                        = 131,
		V408                        = 132,
		ASTC_4X4_TYPELESS           = 133,
		ASTC_4X4_UNORM              = 134,
		ASTC_4X4_UNORM_SRGB         = 135,
		ASTC_5X4_TYPELESS           = 137,
		ASTC_5X4_UNORM              = 138,
		ASTC_5X4_UNORM_SRGB         = 139,
		ASTC_5X5_TYPELESS           = 141,
		ASTC_5X5_UNORM              = 142,
		ASTC_5X5_UNORM_SRGB         = 143,

		ASTC_6X5_TYPELESS           = 145,
		ASTC_6X5_UNORM              = 146,
		ASTC_6X5_UNORM_SRGB         = 147,

		ASTC_6X6_TYPELESS           = 149,
		ASTC_6X6_UNORM              = 150,
		ASTC_6X6_UNORM_SRGB         = 151,

		ASTC_8X5_TYPELESS           = 153,
		ASTC_8X5_UNORM              = 154,
		ASTC_8X5_UNORM_SRGB         = 155,

		ASTC_8X6_TYPELESS           = 157,
		ASTC_8X6_UNORM              = 158,
		ASTC_8X6_UNORM_SRGB         = 159,

		ASTC_8X8_TYPELESS           = 161,
		ASTC_8X8_UNORM              = 162,
		ASTC_8X8_UNORM_SRGB         = 163,

		ASTC_10X5_TYPELESS          = 165,
		ASTC_10X5_UNORM             = 166,
		ASTC_10X5_UNORM_SRGB        = 167,

		ASTC_10X6_TYPELESS          = 169,
		ASTC_10X6_UNORM             = 170,
		ASTC_10X6_UNORM_SRGB        = 171,

		ASTC_10X8_TYPELESS          = 173,
		ASTC_10X8_UNORM             = 174,
		ASTC_10X8_UNORM_SRGB        = 175,

		ASTC_10X10_TYPELESS         = 177,
		ASTC_10X10_UNORM            = 178,
		ASTC_10X10_UNORM_SRGB       = 179,

		ASTC_12X10_TYPELESS         = 181,
		ASTC_12X10_UNORM            = 182,
		ASTC_12X10_UNORM_SRGB       = 183,

		ASTC_12X12_TYPELESS         = 185,
		ASTC_12X12_UNORM            = 186,
		ASTC_12X12_UNORM_SRGB       = 187,

		// Xbox-specific
		R10G10B10_SNORM_A2_UNORM    = 189,
		R4G4_UNORM                  = 190,

		A4B4G4R4_UNORM              = 191,
	};

	struct Header
	{
		unsigned int size;
		unsigned int flags;
		unsigned int height;
		unsigned int width;
		unsigned int pitchOrLinearSize;
		unsigned int depth;
		unsigned int mipMapCount;
		unsigned int reserved1[11];
		PixelFormat ddspf;
		unsigned int caps;
		unsigned int caps2;
		unsigned int caps3;
		unsigned int caps4;
		unsigned int reserved2;
	};

	static_assert(sizeof(Header) == 124, "DDS Header size mismatch");

	struct HeaderDXT10
	{
		DXGIFormat dxgiFormat;
		DXGIResourceDimension resourceDimension;
		unsigned int miscFlag;
		unsigned int arraySize;
		unsigned int miscFlags2;
	};

	static_assert(sizeof(HeaderDXT10) == 20, "DDS DX10 Extended Header size mismatch");

	// Maximum possible size of header. Use this to read in only the header, decode, seek to the real header size, then read in the rest of the image data
	ddspp_constexpr int MAX_HEADER_SIZE = sizeof(DDS_MAGIC) + sizeof(Header) + sizeof(HeaderDXT10);

	enum Result : unsigned char
	{
		Success,
		Error
	};

	enum TextureType : unsigned char
	{
		Texture1D,
		Texture2D,
		Texture3D,
		Cubemap,
	};

	struct Descriptor
	{
		DXGIFormat   format;
		TextureType  type;
		unsigned int width;
		unsigned int height;
		unsigned int depth;
		unsigned int numMips;
		unsigned int arraySize;
		unsigned int rowPitch; // Row pitch for mip 0
		unsigned int depthPitch; // Size of mip 0
		unsigned int bitsPerPixelOrBlock; // If compressed bits per block, else bits per pixel
		unsigned int blockWidth; // Width of block in pixels (1 if uncompressed)
		unsigned int blockHeight;// Height of block in pixels (1 if uncompressed)
		bool         compressed;
		bool         srgb;
		unsigned int headerSize; // Actual size of header, use this to get to image data
	};

	inline ddspp_constexpr bool is_dxt10(const Header& header)
	{
		const PixelFormat& ddspf = header.ddspf;
		return (ddspf.flags & DDS_FOURCC) && (ddspf.fourCC == PF_DXT10.fourCC);
	}

	inline const char* get_dxgi_format_name(DXGIFormat format)
	{
		switch (format)
		{
			case UNKNOWN:                    return "UNKNOWN";
			case R32G32B32A32_TYPELESS:      return "R32G32B32A32_TYPELESS";
			case R32G32B32A32_FLOAT:         return "R32G32B32A32_FLOAT";
			case R32G32B32A32_UINT:          return "R32G32B32A32_UINT";
			case R32G32B32A32_SINT:          return "R32G32B32A32_SINT";
			case R32G32B32_TYPELESS:         return "R32G32B32_TYPELESS";
			case R32G32B32_FLOAT:            return "R32G32B32_FLOAT";
			case R32G32B32_UINT:             return "R32G32B32_UINT";
			case R32G32B32_SINT:             return "R32G32B32_SINT";
			case R16G16B16A16_TYPELESS:      return "R16G16B16A16_TYPELESS";
			case R16G16B16A16_FLOAT:         return "R16G16B16A16_FLOAT";
			case R16G16B16A16_UNORM:         return "R16G16B16A16_UNORM";
			case R16G16B16A16_UINT:          return "R16G16B16A16_UINT";
			case R16G16B16A16_SNORM:         return "R16G16B16A16_SNORM";
			case R16G16B16A16_SINT:          return "R16G16B16A16_SINT";
			case R32G32_TYPELESS:            return "R32G32_TYPELESS";
			case R32G32_FLOAT:               return "R32G32_FLOAT";
			case R32G32_UINT:                return "R32G32_UINT";
			case R32G32_SINT:                return "R32G32_SINT";
			case R32G8X24_TYPELESS:          return "R32G8X24_TYPELESS";
			case D32_FLOAT_S8X24_UINT:       return "D32_FLOAT_S8X24_UINT";
			case R32_FLOAT_X8X24_TYPELESS:   return "R32_FLOAT_X8X24_TYPELESS";
			case X32_TYPELESS_G8X24_UINT:    return "X32_TYPELESS_G8X24_UINT";
			case R10G10B10A2_TYPELESS:       return "R10G10B10A2_TYPELESS";
			case R10G10B10A2_UNORM:          return "R10G10B10A2_UNORM";
			case R10G10B10A2_UINT:           return "R10G10B10A2_UINT";
			case R11G11B10_FLOAT:            return "R11G11B10_FLOAT";
			case R8G8B8A8_TYPELESS:          return "R8G8B8A8_TYPELESS";
			case R8G8B8A8_UNORM:             return "R8G8B8A8_UNORM";
			case R8G8B8A8_UNORM_SRGB:        return "R8G8B8A8_UNORM_SRGB";
			case R8G8B8A8_UINT:              return "R8G8B8A8_UINT";
			case R8G8B8A8_SNORM:             return "R8G8B8A8_SNORM";
			case R8G8B8A8_SINT:              return "R8G8B8A8_SINT";
			case R16G16_TYPELESS:            return "R16G16_TYPELESS";
			case R16G16_FLOAT:               return "R16G16_FLOAT";
			case R16G16_UNORM:               return "R16G16_UNORM";
			case R16G16_UINT:                return "R16G16_UINT";
			case R16G16_SNORM:               return "R16G16_SNORM";
			case R16G16_SINT:                return "R16G16_SINT";
			case R32_TYPELESS:               return "R32_TYPELESS";
			case D32_FLOAT:                  return "D32_FLOAT";
			case R32_FLOAT:                  return "R32_FLOAT";
			case R32_UINT:                   return "R32_UINT";
			case R32_SINT:                   return "R32_SINT";
			case R24G8_TYPELESS:             return "R24G8_TYPELESS";
			case D24_UNORM_S8_UINT:          return "D24_UNORM_S8_UINT";
			case R24_UNORM_X8_TYPELESS:      return "R24_UNORM_X8_TYPELESS";
			case X24_TYPELESS_G8_UINT:       return "X24_TYPELESS_G8_UINT";
			case R8G8_TYPELESS:              return "R8G8_TYPELESS";
			case R8G8_UNORM:                 return "R8G8_UNORM";
			case R8G8_UINT:                  return "R8G8_UINT";
			case R8G8_SNORM:                 return "R8G8_SNORM";
			case R8G8_SINT:                  return "R8G8_SINT";
			case R16_TYPELESS:               return "R16_TYPELESS";
			case R16_FLOAT:                  return "R16_FLOAT";
			case D16_UNORM:                  return "D16_UNORM";
			case R16_UNORM:                  return "R16_UNORM";
			case R16_UINT:                   return "R16_UINT";
			case R16_SNORM:                  return "R16_SNORM";
			case R16_SINT:                   return "R16_SINT";
			case R8_TYPELESS:                return "R8_TYPELESS";
			case R8_UNORM:                   return "R8_UNORM";
			case R8_UINT:                    return "R8_UINT";
			case R8_SNORM:                   return "R8_SNORM";
			case R8_SINT:                    return "R8_SINT";
			case A8_UNORM:                   return "A8_UNORM";
			case R1_UNORM:                   return "R1_UNORM";
			case R9G9B9E5_SHAREDEXP:         return "R9G9B9E5_SHAREDEXP";
			case R8G8_B8G8_UNORM:            return "R8G8_B8G8_UNORM";
			case G8R8_G8B8_UNORM:            return "G8R8_G8B8_UNORM";
			case BC1_TYPELESS:               return "BC1_TYPELESS";
			case BC1_UNORM:                  return "BC1_UNORM";
			case BC1_UNORM_SRGB:             return "BC1_UNORM_SRGB";
			case BC2_TYPELESS:               return "BC2_TYPELESS";
			case BC2_UNORM:                  return "BC2_UNORM";
			case BC2_UNORM_SRGB:             return "BC2_UNORM_SRGB";
			case BC3_TYPELESS:               return "BC3_TYPELESS";
			case BC3_UNORM:                  return "BC3_UNORM";
			case BC3_UNORM_SRGB:             return "BC3_UNORM_SRGB";
			case BC4_TYPELESS:               return "BC4_TYPELESS";
			case BC4_UNORM:                  return "BC4_UNORM";
			case BC4_SNORM:                  return "BC4_SNORM";
			case BC5_TYPELESS:               return "BC5_TYPELESS";
			case BC5_UNORM:                  return "BC5_UNORM";
			case BC5_SNORM:                  return "BC5_SNORM";
			case B5G6R5_UNORM:               return "B5G6R5_UNORM";
			case B5G5R5A1_UNORM:             return "B5G5R5A1_UNORM";
			case B8G8R8A8_UNORM:             return "B8G8R8A8_UNORM";
			case B8G8R8X8_UNORM:             return "B8G8R8X8_UNORM";
			case R10G10B10_XR_BIAS_A2_UNORM: return "R10G10B10_XR_BIAS_A2_UNORM";
			case B8G8R8A8_TYPELESS:          return "B8G8R8A8_TYPELESS";
			case B8G8R8A8_UNORM_SRGB:        return "B8G8R8A8_UNORM_SRGB";
			case B8G8R8X8_TYPELESS:          return "B8G8R8X8_TYPELESS";
			case B8G8R8X8_UNORM_SRGB:        return "B8G8R8X8_UNORM_SRGB";
			case BC6H_TYPELESS:              return "BC6H_TYPELESS";
			case BC6H_UF16:                  return "BC6H_UF16";
			case BC6H_SF16:                  return "BC6H_SF16";
			case BC7_TYPELESS:               return "BC7_TYPELESS";
			case BC7_UNORM:                  return "BC7_UNORM";
			case BC7_UNORM_SRGB:             return "BC7_UNORM_SRGB";
			case AYUV:                       return "AYUV";
			case Y410:                       return "Y410";
			case Y416:                       return "Y416";
			case NV12:                       return "NV12";
			case P010:                       return "P010";
			case P016:                       return "P016";
			case OPAQUE_420:                 return "OPAQUE_420";
			case YUY2:                       return "YUY2";
			case Y210:                       return "Y210";
			case Y216:                       return "Y216";
			case NV11:                       return "NV11";
			case AI44:                       return "AI44";
			case IA44:                       return "IA44";
			case P8:                         return "P8";
			case A8P8:                       return "A8P8";
			case B4G4R4A4_UNORM:             return "B4G4R4A4_UNORM";
			case R10G10B10_7E3_A2_FLOAT:     return "R10G10B10_7E3_A2_FLOAT";
			case R10G10B10_6E4_A2_FLOAT:     return "R10G10B10_6E4_A2_FLOAT";
			case D16_UNORM_S8_UINT:          return "D16_UNORM_S8_UINT";
			case R16_UNORM_X8_TYPELESS:      return "R16_UNORM_X8_TYPELESS";
			case X16_TYPELESS_G8_UINT:       return "X16_TYPELESS_G8_UINT";
			case P208:                       return "P208";
			case V208:                       return "V208";
			case V408:                       return "V408";
			case ASTC_4X4_TYPELESS:          return "ASTC_4X4_TYPELESS";
			case ASTC_4X4_UNORM:             return "ASTC_4X4_UNORM";
			case ASTC_4X4_UNORM_SRGB:        return "ASTC_4X4_UNORM_SRGB";
			case ASTC_5X4_TYPELESS:          return "ASTC_5X4_TYPELESS";
			case ASTC_5X4_UNORM:             return "ASTC_5X4_UNORM";
			case ASTC_5X4_UNORM_SRGB:        return "ASTC_5X4_UNORM_SRGB";
			case ASTC_5X5_TYPELESS:          return "ASTC_5X5_TYPELESS";
			case ASTC_5X5_UNORM:             return "ASTC_5X5_UNORM";
			case ASTC_5X5_UNORM_SRGB:        return "ASTC_5X5_UNORM_SRGB";
			case ASTC_6X5_TYPELESS:          return "ASTC_6X5_TYPELESS";
			case ASTC_6X5_UNORM:             return "ASTC_6X5_UNORM";
			case ASTC_6X5_UNORM_SRGB:        return "ASTC_6X5_UNORM_SRGB";
			case ASTC_6X6_TYPELESS:          return "ASTC_6X6_TYPELESS";
			case ASTC_6X6_UNORM:             return "ASTC_6X6_UNORM";
			case ASTC_6X6_UNORM_SRGB:        return "ASTC_6X6_UNORM_SRGB";
			case ASTC_8X5_TYPELESS:          return "ASTC_8X5_TYPELESS";
			case ASTC_8X5_UNORM:             return "ASTC_8X5_UNORM";
			case ASTC_8X5_UNORM_SRGB:        return "ASTC_8X5_UNORM_SRGB";
			case ASTC_8X6_TYPELESS:          return "ASTC_8X6_TYPELESS";
			case ASTC_8X6_UNORM:             return "ASTC_8X6_UNORM";
			case ASTC_8X6_UNORM_SRGB:        return "ASTC_8X6_UNORM_SRGB";
			case ASTC_8X8_TYPELESS:          return "ASTC_8X8_TYPELESS";
			case ASTC_8X8_UNORM:             return "ASTC_8X8_UNORM";
			case ASTC_8X8_UNORM_SRGB:        return "ASTC_8X8_UNORM_SRGB";
			case ASTC_10X5_TYPELESS:         return "ASTC_10X5_TYPELESS";
			case ASTC_10X5_UNORM:            return "ASTC_10X5_UNORM";
			case ASTC_10X5_UNORM_SRGB:       return "ASTC_10X5_UNORM_SRGB";
			case ASTC_10X6_TYPELESS:         return "ASTC_10X6_TYPELESS";
			case ASTC_10X6_UNORM:            return "ASTC_10X6_UNORM";
			case ASTC_10X6_UNORM_SRGB:       return "ASTC_10X6_UNORM_SRGB";
			case ASTC_10X8_TYPELESS:         return "ASTC_10X8_TYPELESS";
			case ASTC_10X8_UNORM:            return "ASTC_10X8_UNORM";
			case ASTC_10X8_UNORM_SRGB:       return "ASTC_10X8_UNORM_SRGB";
			case ASTC_10X10_TYPELESS:        return "ASTC_10X10_TYPELESS";
			case ASTC_10X10_UNORM:           return "ASTC_10X10_UNORM";
			case ASTC_10X10_UNORM_SRGB:      return "ASTC_10X10_UNORM_SRGB";
			case ASTC_12X10_TYPELESS:        return "ASTC_12X10_TYPELESS";
			case ASTC_12X10_UNORM:           return "ASTC_12X10_UNORM";
			case ASTC_12X10_UNORM_SRGB:      return "ASTC_12X10_UNORM_SRGB";
			case ASTC_12X12_TYPELESS:        return "ASTC_12X12_TYPELESS";
			case ASTC_12X12_UNORM:           return "ASTC_12X12_UNORM";
			case ASTC_12X12_UNORM_SRGB:      return "ASTC_12X12_UNORM_SRGB";
			case R10G10B10_SNORM_A2_UNORM:   return "R10G10B10_SNORM_A2_UNORM";
			case R4G4_UNORM:                 return "R4G4_UNORM";
			case A4B4G4R4_UNORM:             return "A4B4G4R4_UNORM";

			default:
				return "UNKNOWN_FORMAT";
		}
	}

	inline ddspp_constexpr bool is_compressed(DXGIFormat format)
	{
		return (format >= BC1_UNORM && format <= BC5_SNORM) || 
		       (format >= BC6H_TYPELESS && format <= BC7_UNORM_SRGB) || 
		       (format >= ASTC_4X4_TYPELESS && format <= ASTC_12X12_UNORM_SRGB);
	}

	inline ddspp_constexpr bool is_srgb(DXGIFormat format)
	{
		switch(format)
		{
			case R8G8B8A8_UNORM_SRGB:
			case BC1_UNORM_SRGB:
			case BC2_UNORM_SRGB:
			case BC3_UNORM_SRGB:
			case B8G8R8A8_UNORM_SRGB:
			case B8G8R8X8_UNORM_SRGB:
			case BC7_UNORM_SRGB:
			case ASTC_4X4_UNORM_SRGB:
			case ASTC_5X4_UNORM_SRGB:
			case ASTC_5X5_UNORM_SRGB:
			case ASTC_6X5_UNORM_SRGB:
			case ASTC_6X6_UNORM_SRGB:
			case ASTC_8X5_UNORM_SRGB:
			case ASTC_8X6_UNORM_SRGB:
			case ASTC_8X8_UNORM_SRGB:
			case ASTC_10X5_UNORM_SRGB:
			case ASTC_10X6_UNORM_SRGB:
			case ASTC_10X8_UNORM_SRGB:
			case ASTC_10X10_UNORM_SRGB:
			case ASTC_12X10_UNORM_SRGB:
			case ASTC_12X12_UNORM_SRGB:
				return true;
			default:
				return false;
		}
	}

	inline ddspp_constexpr unsigned int get_bits_per_pixel_or_block(DXGIFormat format)
	{
		if(format >= ASTC_4X4_TYPELESS && format <= ASTC_12X12_UNORM_SRGB)
		{
			return 128; // All ASTC blocks are the same size
		}

		switch(format)
		{
			case R1_UNORM:
				return 1;
			case R8_TYPELESS:
			case R8_UNORM:
			case R8_UINT:
			case R8_SNORM:
			case R8_SINT:
			case A8_UNORM:
			case AI44:
			case IA44:
			case P8:
			case R4G4_UNORM:
				return 8;
			case NV12:
			case OPAQUE_420:
			case NV11:
				return 12;
			case R8G8_TYPELESS:
			case R8G8_UNORM:
			case R8G8_UINT:
			case R8G8_SNORM:
			case R8G8_SINT:
			case R16_TYPELESS:
			case R16_FLOAT:
			case D16_UNORM:
			case R16_UNORM:
			case R16_UINT:
			case R16_SNORM:
			case R16_SINT:
			case B5G6R5_UNORM:
			case B5G5R5A1_UNORM:
			case A8P8:
			case B4G4R4A4_UNORM:
				return 16;
			case P010:
			case P016:
			case D16_UNORM_S8_UINT:
			case R16_UNORM_X8_TYPELESS:
			case X16_TYPELESS_G8_UINT:
				return 24;
			case BC1_UNORM:
			case BC1_UNORM_SRGB:
			case BC1_TYPELESS:
			case BC4_UNORM:
			case BC4_SNORM:
			case BC4_TYPELESS:
			case R16G16B16A16_TYPELESS:
			case R16G16B16A16_FLOAT:
			case R16G16B16A16_UNORM:
			case R16G16B16A16_UINT:
			case R16G16B16A16_SNORM:
			case R16G16B16A16_SINT:
			case R32G32_TYPELESS:
			case R32G32_FLOAT:
			case R32G32_UINT:
			case R32G32_SINT:
			case R32G8X24_TYPELESS:
			case D32_FLOAT_S8X24_UINT:
			case R32_FLOAT_X8X24_TYPELESS:
			case X32_TYPELESS_G8X24_UINT:
			case Y416:
			case Y210:
			case Y216:
				return 64;
			case R32G32B32_TYPELESS:
			case R32G32B32_FLOAT:
			case R32G32B32_UINT:
			case R32G32B32_SINT:
				return 96;
			case BC2_UNORM:
			case BC2_UNORM_SRGB:
			case BC2_TYPELESS:
			case BC3_UNORM:
			case BC3_UNORM_SRGB:
			case BC3_TYPELESS:
			case BC5_UNORM:
			case BC5_SNORM:
			case BC6H_UF16:
			case BC6H_SF16:
			case BC7_UNORM:
			case BC7_UNORM_SRGB:
			case R32G32B32A32_TYPELESS:
			case R32G32B32A32_FLOAT:
			case R32G32B32A32_UINT:
			case R32G32B32A32_SINT:
				return 128;
			default:
				return 32; // Most formats are 32 bits per pixel
				break;
		}
	}

	inline ddspp_constexpr void get_block_size(DXGIFormat format, unsigned int& blockWidth, unsigned int& blockHeight)
	{
		switch(format)
		{
			case BC1_UNORM:
			case BC1_UNORM_SRGB:
			case BC1_TYPELESS:
			case BC4_UNORM:
			case BC4_SNORM:
			case BC4_TYPELESS:
			case BC2_UNORM:
			case BC2_UNORM_SRGB:
			case BC2_TYPELESS:
			case BC3_UNORM:
			case BC3_UNORM_SRGB:
			case BC3_TYPELESS:
			case BC5_UNORM:
			case BC5_SNORM:
			case BC6H_UF16:
			case BC6H_SF16:
			case BC7_UNORM:
			case BC7_UNORM_SRGB:
			case ASTC_4X4_TYPELESS:
			case ASTC_4X4_UNORM:
			case ASTC_4X4_UNORM_SRGB:
				blockWidth = 4; blockHeight = 4;
				break;
			case ASTC_5X4_TYPELESS:
			case ASTC_5X4_UNORM:
			case ASTC_5X4_UNORM_SRGB:
				blockWidth = 5; blockHeight = 4;
				break;
			case ASTC_5X5_TYPELESS:
			case ASTC_5X5_UNORM:
			case ASTC_5X5_UNORM_SRGB:
				blockWidth = 5; blockHeight = 5;
				break;
			case ASTC_6X5_TYPELESS:
			case ASTC_6X5_UNORM:
			case ASTC_6X5_UNORM_SRGB:
				blockWidth = 6; blockHeight = 5;
				break;
			case ASTC_6X6_TYPELESS:
			case ASTC_6X6_UNORM:
			case ASTC_6X6_UNORM_SRGB:
				blockWidth = 6; blockHeight = 6;
				break;
			case ASTC_8X5_TYPELESS:
			case ASTC_8X5_UNORM:
			case ASTC_8X5_UNORM_SRGB:
				blockWidth = 8; blockHeight = 5;
				break;
			case ASTC_8X6_TYPELESS:
			case ASTC_8X6_UNORM:
			case ASTC_8X6_UNORM_SRGB:
				blockWidth = 8; blockHeight = 6;
				break;
			case ASTC_8X8_TYPELESS:
			case ASTC_8X8_UNORM:
			case ASTC_8X8_UNORM_SRGB:
				blockWidth = 8; blockHeight = 8;
				break;
			case ASTC_10X5_TYPELESS:
			case ASTC_10X5_UNORM:
			case ASTC_10X5_UNORM_SRGB:
				blockWidth = 10; blockHeight = 5;
				break;
			case ASTC_10X6_TYPELESS:
			case ASTC_10X6_UNORM:
			case ASTC_10X6_UNORM_SRGB:
				blockWidth = 10; blockHeight = 6;
				break;
			case ASTC_10X8_TYPELESS:
			case ASTC_10X8_UNORM:
			case ASTC_10X8_UNORM_SRGB:
				blockWidth = 10; blockHeight = 8;
				break;
			case ASTC_10X10_TYPELESS:
			case ASTC_10X10_UNORM:
			case ASTC_10X10_UNORM_SRGB:
				blockWidth = 10; blockHeight = 10;
				break;
			case ASTC_12X10_TYPELESS:
			case ASTC_12X10_UNORM:
			case ASTC_12X10_UNORM_SRGB:
				blockWidth = 12; blockHeight = 10;
				break;
			case ASTC_12X12_TYPELESS:
			case ASTC_12X12_UNORM:
			case ASTC_12X12_UNORM_SRGB:
				blockWidth = 12; blockHeight = 12;
				break;
			default:
				blockWidth = 1; blockHeight = 1;
				break;
		}

		return;
	}

	inline bool has_alpha_channel(DXGIFormat format)
	{
		switch(format)
		{
			case R32G32B32A32_TYPELESS:
			case R32G32B32A32_FLOAT:
			case R32G32B32A32_UINT:
			case R32G32B32A32_SINT:
			case R16G16B16A16_TYPELESS:
			case R16G16B16A16_FLOAT:
			case R16G16B16A16_UNORM:
			case R16G16B16A16_UINT:
			case R16G16B16A16_SNORM:
			case R16G16B16A16_SINT:
			case R10G10B10A2_TYPELESS:
			case R10G10B10A2_UNORM:
			case R10G10B10A2_UINT:
			case R8G8B8A8_TYPELESS:
			case R8G8B8A8_UNORM:
			case R8G8B8A8_UNORM_SRGB:
			case R8G8B8A8_UINT:
			case R8G8B8A8_SNORM:
			case R8G8B8A8_SINT:
			case A8_UNORM:
			case BC1_TYPELESS:
			case BC1_UNORM:
			case BC1_UNORM_SRGB:
			case BC2_TYPELESS:
			case BC2_UNORM:
			case BC2_UNORM_SRGB:
			case BC3_TYPELESS:
			case BC3_UNORM:
			case BC3_UNORM_SRGB:
			case B5G5R5A1_UNORM:
			case B8G8R8A8_UNORM:
			case R10G10B10_XR_BIAS_A2_UNORM:
			case B8G8R8A8_TYPELESS:
			case B8G8R8A8_UNORM_SRGB:
			case BC7_TYPELESS:
			case BC7_UNORM:
			case BC7_UNORM_SRGB:
			case AYUV:
			case Y410:
			case Y416:
			case AI44:
			case IA44:
			case A8P8:
			case B4G4R4A4_UNORM:
			case R10G10B10_7E3_A2_FLOAT:
			case R10G10B10_6E4_A2_FLOAT:
			case R10G10B10_SNORM_A2_UNORM:
			case A4B4G4R4_UNORM:
				return true;
			default:
				return false;
		}
	}

	// Returns number of bytes for each row of a given mip. Valid range is [0, desc.numMips)
	inline ddspp_constexpr unsigned int get_row_pitch(unsigned int width, unsigned int bitsPerPixelOrBlock, unsigned int blockWidth, unsigned int mip)
	{
		// Shift width by mipmap index, round to next block size and round to next byte (for the rare less than 1 byte per pixel formats)
		// E.g. width = 119, mip = 3, BC1 compression
		// ((((119 >> 2) + 4 - 1) / 4) * 64) / 8 = 64 bytes
		return ((((((width >> mip) > 1) ? (width >> mip) : 1) + blockWidth - 1) / blockWidth) * bitsPerPixelOrBlock + 7) / 8;
	}

	inline ddspp_constexpr unsigned int get_row_pitch(const Descriptor& desc, unsigned int mip)
	{
		return get_row_pitch(desc.width, desc.bitsPerPixelOrBlock, desc.blockWidth, mip);
	}

	// Return the height for a given mip in either pixels or blocks depending on whether the format is compressed
	inline ddspp_constexpr unsigned int get_height_pixels_blocks(const unsigned int height, const unsigned int blockHeight, const unsigned int mip)
	{
		return ((height / blockHeight) >> mip) ? ((height / blockHeight) >> mip) : 1;
	}

	inline ddspp_constexpr unsigned int get_height_pixels_blocks(const Descriptor& desc, const unsigned int mip)
	{
		return get_height_pixels_blocks(desc.height, desc.blockHeight, mip);
	}

	inline Result decode_header(const unsigned char* sourceData, Descriptor& desc)
	{
		unsigned int magic = *reinterpret_cast<const unsigned int*>(sourceData); // First 4 bytes are the magic DDS number

		if (magic != DDS_MAGIC)
		{
			return ddspp::Error;
		}

		const Header header = *reinterpret_cast<const Header*>(sourceData + sizeof(DDS_MAGIC));
		const PixelFormat& ddspf = header.ddspf;
		bool dxt10Extension = is_dxt10(header);
		const HeaderDXT10 dxt10Header = *reinterpret_cast<const HeaderDXT10*>(sourceData + sizeof(DDS_MAGIC) + sizeof(Header));

		// Read basic data from the header
		desc.width = header.width > 0 ? header.width : 1;
		desc.height = header.height > 0 ? header.height : 1;
		desc.depth = header.depth > 0 ? header.depth : 1;
		desc.numMips = header.mipMapCount > 0 ? header.mipMapCount : 1;

		// Set some sensible defaults
		desc.arraySize = 1;
		desc.srgb = false;
		desc.type = Texture2D;
		desc.format = UNKNOWN;

		if (dxt10Extension)
		{
			desc.format = dxt10Header.dxgiFormat;

			desc.arraySize = dxt10Header.arraySize;

			switch(dxt10Header.resourceDimension)
			{
				case DXGI_Texture1D:
					desc.depth = 1;
					desc.type = Texture1D;
					break;
				case DXGI_Texture2D:
					desc.depth = 1;

					if(dxt10Header.miscFlag & DXGI_MISC_FLAG_CUBEMAP)
					{
						desc.type = Cubemap;
					}
					else
					{
						desc.type = Texture2D;
					}

					break;
				case DXGI_Texture3D:
					desc.type = Texture3D;
					desc.arraySize = 1; // There are no 3D texture arrays
					break;
				default:
					break;
			}
		}
		else
		{
			if(ddspf.flags & DDS_FOURCC)
			{
				FourCC::T fourCC = ddspf.fourCC;

				// Compressed
				if(fourCC == PF_DXT1.fourCC)
				{
					desc.format = BC1_UNORM;
				}
				else if(fourCC == PF_DXT2.fourCC || fourCC == PF_DXT3.fourCC)
				{
					desc.format = BC2_UNORM;
				}
				else if(fourCC == PF_DXT4.fourCC || fourCC == PF_DXT5.fourCC)
				{
					desc.format = BC3_UNORM;
				}
				else if(fourCC == PF_ATI1.fourCC || fourCC == PF_BC4U.fourCC)
				{
					desc.format = BC4_UNORM;
				}
				else if(fourCC == PF_BC4S.fourCC)
				{
					desc.format = BC4_SNORM;
				}
				else if(fourCC == PF_ATI2.fourCC || fourCC == PF_BC5U.fourCC)
				{
					desc.format = BC5_UNORM;
				}
				else if(fourCC == PF_BC5S.fourCC)
				{
					desc.format = BC5_SNORM;
				}
				else if (fourCC == PF_BC6H.fourCC)
				{
					desc.format = BC6H_UF16;
				}
				else if (fourCC == PF_BC7L.fourCC)
				{
					desc.format = BC7_UNORM;
				}
				else if (fourCC == PF_BC70.fourCC)
				{
					desc.format = BC7_UNORM;
				}
				else if (fourCC == PF_ZOLA.fourCC)
				{
					desc.format = BC7_UNORM;
				}

				// Video
				else if(fourCC == PF_RGBG.fourCC)
				{
					desc.format = R8G8_B8G8_UNORM;
				}
				else if(fourCC == PF_GRBG.fourCC)
				{
					desc.format = G8R8_G8B8_UNORM;
				}
				else if(fourCC == PF_YUY2.fourCC)
				{
					desc.format = YUY2;
				}

				// Packed
				else if(fourCC == PF_A8.fourCC)
				{
					desc.format = R8_UNORM;
				}
				else if(fourCC == PF_A2B10G10R10.fourCC)
				{
					desc.format = R10G10B10A2_UNORM;
				}
				else if(fourCC == PF_A16B16G16R16.fourCC)
				{
					desc.format = R16G16B16A16_UNORM;
				}
				else if(fourCC == PF_Q16W16V16U16.fourCC)
				{
					desc.format = R16G16B16A16_SNORM;
				}
				else if(fourCC == PF_R16F.fourCC)
				{
					desc.format = R16_FLOAT;
				}
				else if(fourCC == PF_R16G16F.fourCC)
				{
					desc.format = R16G16_FLOAT;
				}
				else if(fourCC == PF_A16B16G16R16F.fourCC)
				{
					desc.format = R16G16B16A16_FLOAT;
				}
				else if(fourCC == PF_R32F.fourCC)
				{
					desc.format = R32_FLOAT;
				}
				else if(fourCC == PF_R32G32F.fourCC)
				{
					desc.format = R32G32_FLOAT;
				}
				else if(fourCC == PF_A32B32G32R32F.fourCC)
				{
					desc.format = R32G32B32A32_FLOAT;
				}
			}
			else if(ddspf.flags & DDS_RGB)
			{
				if (is_rgba_mask(ddspf, PF_A8B8G8R8))
				{
					desc.format = R8G8B8A8_UNORM;
				}
				else if (is_rgba_mask(ddspf, PF_A8R8G8B8))
				{
					desc.format = B8G8R8A8_UNORM;
				}
				else if (is_rgba_mask(ddspf, PF_X8R8G8B8))
				{
					desc.format = B8G8R8X8_UNORM;
				}
				else if (is_rgba_mask(ddspf, PF_A2R10G10B10))
				{
					desc.format = R10G10B10A2_UNORM;
				}
				else if (is_rgba_mask(ddspf, PF_G16R16))
				{
					desc.format = R16G16_UNORM;
				}
				else if (is_rgba_mask(ddspf, PF_R32F))
				{
					desc.format = R32_FLOAT;
				}
				else if (is_rgba_mask(ddspf, PF_A1R5G5B5))
				{
					desc.format = B5G5R5A1_UNORM;
				}
				else if (is_rgba_mask(ddspf, PF_R5G6B5))
				{
					desc.format = B5G6R5_UNORM;
				}
				else if (is_rgba_mask(ddspf, PF_A4R4G4B4))
				{
					desc.format = B4G4R4A4_UNORM;
				}

				// No DXGI format maps to (0x000000ff, 0x0000ff00, 0x00ff0000, 0x00000000) aka D3DFMT_X8B8G8R8
				// No DXGI format maps to (0x000003ff, 0x000ffc00, 0x3ff00000, 0xc0000000) aka D3DFMT_A2R10G10B10
				// No DXGI format maps to (0x7c00, 0x03e0, 0x001f, 0x0000) aka D3DFMT_X1R5G5B5.
				// No DXGI format maps to (0x0f00, 0x00f0, 0x000f, 0x0000) aka D3DFMT_X4R4G4B4.
				// No 3:3:2, 3:3:2:8, or paletted DXGI formats aka D3DFMT_A8R3G3B2, D3DFMT_R3G3B2, D3DFMT_P8, D3DFMT_A8P8, etc.
				// D3DFMT_A2W10V10U10 maps to (0x3ff00000, 0x000ffc00, 0x000003ff, 0xc0000000)

				// Note that many common DDS reader/writers (including D3DX) swap the
				// the RED/BLUE masks for 10:10:10:2 formats. We assume
				// below that the 'backwards' header mask is being used since it is most
				// likely written by D3DX. The more robust solution is to use the 'DX10'
				// header extension and specify the DXGI_FORMAT_R10G10B10A2_UNORM format directly
			}
			else if (ddspf.flags & DDS_LUMINANCE)
			{
				if (is_rgba_mask(ddspf, PF_L16))
				{
					desc.format = R16_UNORM;
				}
				else if (is_rgba_mask(ddspf, PF_A8L8))
				{
					desc.format = R8G8_UNORM;
				}
				else if (is_rgba_mask(ddspf, PF_L8))
				{
					desc.format = R8_UNORM;
				}

				// No DXGI format maps to (0x0f, 0x00, 0x00, 0xf0) aka D3DFMT_A4L4
			}
			else if (ddspf.flags & DDS_ALPHA)
			{
				switch(ddspf.RGBBitCount)
				{
					case 8:
						desc.format = A8_UNORM;
						break;
					case 16:
						desc.format = R16_UNORM;
						break;
				}
			}
			else if (ddspf.flags & DDS_BUMPDUDV)
			{
				if (is_rgba_mask(ddspf, PF_Q8W8V8U8))
				{
					desc.format = R8G8B8A8_SNORM;
				}
				else if (is_rgba_mask(ddspf, PF_V16U16))
				{
					desc.format = R16G16_SNORM;
				}
				else if (is_rgba_mask(ddspf, PF_V8U8))
				{
					desc.format = R8G8_SNORM;
				}
			}

			if((header.flags & DDS_HEADER_FLAGS_VOLUME) || (header.caps2 & DDS_HEADER_CAPS2_VOLUME))
			{
				desc.type = Texture3D;
			}
			else if (header.caps2 & DDS_HEADER_CAPS2_CUBEMAP)
			{
				if((header.caps2 & DDS_HEADER_CAPS2_CUBEMAP_ALLFACES) != DDS_HEADER_CAPS2_CUBEMAP_ALLFACES)
				{
					return ddspp::Error;
				}

				desc.type = Cubemap;
				desc.arraySize = 1;
				desc.depth = 1;
			}
			else
			{
				desc.type = Texture2D;
			}
		}

		desc.compressed = is_compressed(desc.format);
		desc.srgb = is_srgb(desc.format);
		desc.bitsPerPixelOrBlock = get_bits_per_pixel_or_block(desc.format);
		get_block_size(desc.format, desc.blockWidth, desc.blockHeight);
		
		desc.rowPitch = get_row_pitch(desc.width, desc.bitsPerPixelOrBlock, desc.blockWidth, 0);
		desc.depthPitch = desc.rowPitch * desc.height / desc.blockHeight;
		desc.headerSize = sizeof(DDS_MAGIC) + sizeof(Header) + (dxt10Extension ? sizeof(HeaderDXT10) : 0);

		return ddspp::Success;
	}

	inline void encode_header(const DXGIFormat dxgiFormat, const unsigned int width, const unsigned int height, const unsigned int depth,
	                          const TextureType type, const unsigned int mipCount, const unsigned int arraySize, 
	                          Header& header, HeaderDXT10& dxt10Header)
	{
		header.size = sizeof(Header);

		// Fill in header flags
		header.flags = DDS_HEADER_FLAGS_CAPS | DDS_HEADER_FLAGS_HEIGHT | DDS_HEADER_FLAGS_WIDTH | DDS_HEADER_FLAGS_PIXELFORMAT;
		header.caps = DDS_HEADER_CAPS_TEXTURE;
		header.caps2 = 0;

		if (mipCount > 1)
		{
			header.flags |= DDS_HEADER_FLAGS_MIPMAP;
			header.caps |= DDS_HEADER_CAPS_COMPLEX | DDS_HEADER_CAPS_MIPMAP;
		}

		unsigned int bitsPerPixelOrBlock = get_bits_per_pixel_or_block(dxgiFormat);

		if (is_compressed(dxgiFormat))
		{
			header.flags |= DDS_HEADER_FLAGS_LINEARSIZE;
			unsigned int blockWidth, blockHeight;
			get_block_size(dxgiFormat, blockWidth, blockHeight);
			header.pitchOrLinearSize = width * height * bitsPerPixelOrBlock / (8 * blockWidth * blockHeight);
		}
		else
		{
			header.flags |= DDS_HEADER_FLAGS_PITCH;
			header.pitchOrLinearSize = width * bitsPerPixelOrBlock / 8;
		}

		header.height = height;
		header.width = width;
		header.depth = depth;
		header.mipMapCount = mipCount;
		header.reserved1[0] = header.reserved1[1] = header.reserved1[2] = 0;
		header.reserved1[3] = header.reserved1[4] = header.reserved1[5] = 0;
		header.reserved1[6] = header.reserved1[7] = header.reserved1[8] = 0;
		header.reserved1[9] = header.reserved1[10] = 0;
		
		// Fill in pixel format
		PixelFormat& ddspf = header.ddspf;
		ddspf.size = sizeof(PixelFormat);
		ddspf.fourCC = PF_DXT10.fourCC;
		ddspf.flags = 0;
		ddspf.flags |= DDS_FOURCC;

		// Add a way to store as the DX9 header
		ddspf.RGBBitCount = 0;
		ddspf.RBitMask = 0;
		ddspf.GBitMask = 0;
		ddspf.BBitMask = 0;
		ddspf.ABitMask = 0;

		dxt10Header.dxgiFormat = dxgiFormat;
		dxt10Header.arraySize = arraySize;
		dxt10Header.miscFlag = 0;
		
		if (type == Texture1D)
		{
			dxt10Header.resourceDimension = DXGI_Texture1D;
		}
		else if (type == Texture2D)
		{
			dxt10Header.resourceDimension = DXGI_Texture2D;
		}
		else if (type == Cubemap)
		{
			dxt10Header.resourceDimension = DXGI_Texture2D;
			dxt10Header.miscFlag |= DXGI_MISC_FLAG_CUBEMAP;
			header.caps |= DDS_HEADER_CAPS_COMPLEX;
			header.caps2 |= DDS_HEADER_CAPS2_CUBEMAP | DDS_HEADER_CAPS2_CUBEMAP_ALLFACES;
		}
		else if (type == Texture3D)
		{
			dxt10Header.resourceDimension = DXGI_Texture3D;
			header.flags |= DDS_HEADER_FLAGS_VOLUME;
			header.caps2 |= DDS_HEADER_CAPS2_VOLUME;
		}

		// I don't think this gives us a lot of information unless we can supply it externally. It's metadata related to how the alpha
		// channel has been factored into the texture. The format already gives us a lot to go on; the situations where this is ambiguous
		// are BC1_UNORM (1-bit alpha) and premultiplied. None of them can be deduced from the data we are being supplied currently
		dxt10Header.miscFlags2 = DDS_ALPHA_MODE_UNKNOWN;

		// Unused
		header.caps3 = 0;
		header.caps4 = 0;
		header.reserved2 = 0;
	}

	// The mip/slice arrangement is different between texture arrays and volume textures
	//
	// Arrays
	//  __________  _____  __  __________  _____  __  __________  _____  __ 
	// |          ||     ||__||          ||     ||__||          ||     ||__|
	// |          ||_____|    |          ||_____|    |          ||_____|
	// |          |           |          |           |          |
	// |__________|           |__________|           |__________|
	//
	// Volume
	//  __________  __________  __________  __________  _____  _____  __ 
	// |          ||          ||          ||          ||     ||     ||__|
	// |          ||          ||          ||          ||_____||_____|
	// |          ||          ||          ||          |
	// |__________||__________||__________||__________|
	//

	// Returns the size in bytes of the entire texture
	inline ddspp_constexpr unsigned int get_size(const Descriptor& desc)
	{
		unsigned long long size = 0;

		if (desc.type == Texture3D)
		{
			for (unsigned int m = 0; m < desc.numMips; ++m)
			{
				unsigned int mipWidth        = (desc.width >> m) > 1 ? (desc.width >> m) : 1;
				unsigned int mipHeight       = (desc.height >> m) > 1 ? (desc.height >> m) : 1;
				unsigned int mipDepth        = (desc.height >> m) > 1 ? (desc.height >> m) : 1;
				unsigned int mipBlocksWidth  = (mipWidth + desc.blockWidth - 1) / desc.blockWidth;
				unsigned int mipBlocksHeight = (mipHeight + desc.blockHeight - 1) / desc.blockHeight;
				unsigned long long mipSize = mipBlocksWidth * mipBlocksHeight * mipDepth * desc.bitsPerPixelOrBlock;
				size += mipSize;
			}
		}
		else
		{
			for (unsigned int m = 0; m < desc.numMips; ++m)
			{
				unsigned int mipWidth        = (desc.width >> m) > 1 ? (desc.width >> m) : 1;
				unsigned int mipHeight       = (desc.height >> m) > 1 ? (desc.height >> m) : 1;
				unsigned int mipBlocksWidth  = (mipWidth + desc.blockWidth - 1) / desc.blockWidth;
				unsigned int mipBlocksHeight = (mipHeight + desc.blockHeight - 1) / desc.blockHeight;
				unsigned long long mipSize   = mipBlocksWidth * mipBlocksHeight * desc.bitsPerPixelOrBlock;
				size += mipSize;
			}

			size *= desc.arraySize;
		}

		size /= 8;

		return (unsigned int)size;
	}

	// Returns the offset in bytes from the base pointer to the desired mip and slice
	// Slice is either a texture from an array, a face from a cubemap, or a 2D slice of a volume texture
	// Be careful when specifying the slice of a volume texture, as every mip has half the slices of the previous
	// For example, in a 64x64x64 texture, get_offset(desc, 1, 63) is incorrectly specified
	inline ddspp_constexpr unsigned int get_offset(const Descriptor& desc, const unsigned int mip, const unsigned int slice)
	{
		unsigned long long offset = 0;

		if (desc.type == Texture3D)
		{
			unsigned long long mipChainSize = 0;

			for (unsigned int m = 0; m < mip; ++m)
			{
				unsigned int mipWidth        = (desc.width >> m) > 1 ? (desc.width >> m) : 1;
				unsigned int mipHeight       = (desc.height >> m) > 1 ? (desc.height >> m) : 1;
				unsigned int mipDepth        = (desc.depth >> m) > 1 ? (desc.depth >> m) : 1;
				unsigned int mipBlocksWidth  = (mipWidth + desc.blockWidth - 1) / desc.blockWidth;
				unsigned int mipBlocksHeight = (mipHeight + desc.blockHeight - 1) / desc.blockHeight;
				unsigned long long mipSize   = mipBlocksWidth * mipBlocksHeight * mipDepth * desc.bitsPerPixelOrBlock;
				mipChainSize += mipSize;
			}

			offset += mipChainSize;

			unsigned int lastMipWidth        = (desc.width >> mip) > 1 ? (desc.width >> mip) : 1;
			unsigned int lastMipHeight       = (desc.height >> mip) > 1 ? (desc.height >> mip) : 1;
			unsigned int lastMipDepth        = (desc.depth >> mip) > 1 ? (desc.depth >> mip) : 1;
			unsigned int lastMipBlocksWidth  = (lastMipWidth + desc.blockWidth - 1) / desc.blockWidth;
			unsigned int lastMipBlocksHeight = (lastMipHeight + desc.blockHeight - 1) / desc.blockHeight;
			unsigned long long lastMipSize   = lastMipBlocksWidth * lastMipBlocksHeight * lastMipDepth * desc.bitsPerPixelOrBlock;

			offset += lastMipSize * slice;
		}
		else
		{
			unsigned long long mipChainSize = 0;

			for (unsigned int m = 0; m < desc.numMips; ++m)
			{
				unsigned int mipWidth        = (desc.width >> m) > 1 ? (desc.width >> m) : 1;
				unsigned int mipHeight       = (desc.height >> m) > 1 ? (desc.height >> m) : 1;
				unsigned int mipBlocksWidth  = (mipWidth + desc.blockWidth - 1) / desc.blockWidth;
				unsigned int mipBlocksHeight = (mipHeight + desc.blockHeight - 1) / desc.blockHeight;
				mipChainSize += mipBlocksWidth * mipBlocksHeight * desc.bitsPerPixelOrBlock;
			}

			offset += mipChainSize * slice;

			for (unsigned int m = 0; m < mip; ++m)
			{
				unsigned int mipWidth        = (desc.width >> m) > 1 ? (desc.width >> m) : 1;
				unsigned int mipHeight       = (desc.height >> m) > 1 ? (desc.height >> m) : 1;
				unsigned int mipBlocksWidth  = (mipWidth + desc.blockWidth - 1) / desc.blockWidth;
				unsigned int mipBlocksHeight = (mipHeight + desc.blockHeight - 1) / desc.blockHeight;
				offset += mipBlocksWidth * mipBlocksHeight * desc.bitsPerPixelOrBlock;
			}
		}

		offset /= 8; // Back to bytes

		return (unsigned int)offset;
	}
}

ddspp_warning_underlying_enum_type_end