#include <stdio.h>
#include <stdlib.h>	//to use system()
#include <string.h> 
#include <stdint.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#define CHANNEL_NUM 3
int main()
{
	
	int width, height, bpp;

    uint8_t* rgb_image = stbi_load("index.jpeg", &width, &height, &bpp, 3); // reading  jpeg image
    stbi_image_free(rgb_image);
    printf("Width: %d\nHeight: %d\nBPP: %d\n",width,height,bpp);
    uint8_t* rgb_image1 =(uint8_t*)malloc(width*height*CHANNEL_NUM);
   
	printf("Imagemagick  \n");
	//sudo apt install imagemagick
	printf("--------------------IMAGE METADATA-------------------------------------\n");  // writing image metadata
	system("identify -verbose index.jpeg");
	printf("-----------------------------------------------------------------------\n");
	printf("Convert rgb to grayscale \n");
	system("convert index.jpeg -set colorspace Gray -separate -average gray.jpeg");     // writing grayscale image
	system("ls");
	printf("-----------------------------------------------------------------------\n");
	printf("Convert rgb to negetive \n");
	system("convert  index.jpeg  -negate  test_negate.jpeg");                           // writing negetive image
	system("ls");
	printf("-----------------------------------------------------------------------\n");
	printf("Convert rgb to black and white with threshold \n");
	system("convert index.jpeg -threshold 50% black_white.jpeg");                      // writing black and white image
	system("ls");
	
	printf("-----------------------------------------------------------------------\n");
	printf("Convert jpeg to png \n");
	system("convert index.jpeg index.png");                           // converting jpeg to  png image
	system("ls");
	
	
	
	
	return 0;
}




/***************************OUTPUT****************************************
students@CE-Lab-602-U12:~/Downloads/exp1$ g++ exp1.c
students@CE-Lab-602-U12:~/Downloads/exp1$ ./a.out
Width: 3264
Height: 2448
BPP: 3
Imagemagick  
--------------------IMAGE METADATA-------------------------------------
Image: index.jpeg
  Format: JPEG (Joint Photographic Experts Group JFIF format)
  Mime type: image/jpeg
  Class: DirectClass
  Geometry: 3264x2448+0+0
  Resolution: 72x72
  Print size: 45.3333x34
  Units: PixelsPerInch
  Type: TrueColor
  Endianess: Undefined
  Colorspace: sRGB
  Depth: 8-bit
  Channel depth:
    red: 8-bit
    green: 8-bit
    blue: 8-bit
  Channel statistics:
    Pixels: 7990272
    Red:
      min: 0 (0)
      max: 255 (1)
      mean: 160.004 (0.627467)
      standard deviation: 57.662 (0.226126)
      kurtosis: -0.96641
      skewness: -0.403263
    Green:
      min: 0 (0)
      max: 255 (1)
      mean: 147.239 (0.577409)
      standard deviation: 67.8997 (0.266273)
      kurtosis: -1.28445
      skewness: -0.319878
    Blue:
      min: 0 (0)
      max: 255 (1)
      mean: 150.688 (0.590934)
      standard deviation: 65.0749 (0.255196)
      kurtosis: -1.30013
      skewness: -0.278204
  Image statistics:
    Overall:
      min: 0 (0)
      max: 255 (1)
      mean: 152.644 (0.598603)
      standard deviation: 63.692 (0.249773)
      kurtosis: -1.13838
      skewness: -0.361308
  Rendering intent: Perceptual
  Gamma: 0.454545
  Chromaticity:
    red primary: (0.64,0.33)
    green primary: (0.3,0.6)
    blue primary: (0.15,0.06)
    white point: (0.3127,0.329)
  Background color: white
  Border color: srgb(223,223,223)
  Matte color: grey74
  Transparent color: black
  Interlace: None
  Intensity: Undefined
  Compose: Over
  Page geometry: 3264x2448+0+0
  Dispose: Undefined
  Iterations: 0
  Compression: JPEG
  Quality: 96
  Orientation: TopLeft
  Properties:
    date:create: 2019-08-07T12:20:20+06:00
    date:modify: 2019-08-07T12:17:59+06:00
    exif:ApertureValue: 185/100
    exif:BrightnessValue: -92/100
    exif:ColorSpace: 1
    exif:ComponentsConfiguration: 1, 2, 3, 0
    exif:DateTime: 2019:08:07 12:15:58
    exif:DateTimeDigitized: 2019:08:07 12:15:58
    exif:DateTimeOriginal: 2019:08:07 12:15:58
    exif:ExifImageLength: 2448
    exif:ExifImageWidth: 3264
    exif:ExifOffset: 238
    exif:ExifVersion: 48, 50, 50, 48
    exif:ExposureBiasValue: 0/10
    exif:ExposureMode: 0
    exif:ExposureProgram: 0
    exif:ExposureTime: 1/14
    exif:Flash: 0
    exif:FlashPixVersion: 48, 49, 48, 48
    exif:FNumber: 190/100
    exif:FocalLength: 253/100
    exif:FocalLengthIn35mmFilm: 27
    exif:GPSAltitude: 0/1000
    exif:GPSAltitudeRef: 0
    exif:GPSDateStamp: 2019:08:07
    exif:GPSInfo: 6788
    exif:GPSLatitude: 0/1, 0/1, 0/10000
    exif:GPSLatitudeRef: N
    exif:GPSLongitude: 0/1, 0/1, 0/10000
    exif:GPSLongitudeRef: E
    exif:GPSTimeStamp: 6/1, 45/1, 57/1
    exif:GPSVersionID: 2, 2, 0, 0
    exif:ImageLength: 2448
    exif:ImageUniqueID: Z08QLLA00CM Z08QLLA00CA
    exif:ImageWidth: 3264
    exif:InteroperabilityOffset: 6758
    exif:ISOSpeedRatings: 320
    exif:LightSource: 0
    exif:Make: samsung
    exif:MakerNote: 7, 0, 1, 0, 7, 0, 4, 0, 0, 0, 48, 49, 48, 48, 2, 0, 4, 0, 1, 0, 0, 0, 0, 32, 1, 0, 12, 0, 4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 16, 0, 5, 0, 1, 0, 0, 0, 90, 0, 0, 0, 64, 0, 4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 80, 0, 4, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    exif:MaxApertureValue: 185/100
    exif:MeteringMode: 2
    exif:Model: SM-J610F
    exif:Orientation: 1
    exif:ResolutionUnit: 2
    exif:SceneCaptureType: 0
    exif:SceneType: 1
    exif:SensingMethod: 2
    exif:ShutterSpeedValue: 3836/1000
    exif:Software: J610FXXU2BSF6
    exif:thumbnail:Compression: 6
    exif:thumbnail:ImageLength: 376
    exif:thumbnail:ImageWidth: 504
    exif:thumbnail:InteroperabilityIndex: R98
    exif:thumbnail:InteroperabilityVersion: 48, 49, 48, 48
    exif:thumbnail:JPEGInterchangeFormat: 7124
    exif:thumbnail:JPEGInterchangeFormatLength: 14827
    exif:thumbnail:Orientation: 1
    exif:thumbnail:ResolutionUnit: 2
    exif:thumbnail:XResolution: 72/1
    exif:thumbnail:YResolution: 72/1
    exif:UserComment: 65, 83, 67, 73, 73, 0, 0, 0, 35, 92, 0, 0, 179, 232, 0, 0, 204, 112, 0, 0, 164, 160, 0, 0, 239, 130, 0, 0, 8, 137, 0, 0, 239, 130, 0, 0, 8, 137, 0, 0, 87, 144, 0, 0, 105, 111, 0, 0, 252, 158, 0, 0, 81, 115, 0, 0, 144, 201, 0, 0, 164, 86, 0, 0, 53, 59, 1, 0, 13, 62, 0, 0, 87, 144, 0, 0, 105, 111, 0, 0, 239, 130, 0, 0, 8, 137, 0, 0, 144, 201, 0, 0, 164, 86, 0, 0, 144, 201, 0, 0, 164, 86, 0, 0, 3, 0, 0, 0, 4, 233, 1, 0, 0, 0, 1, 0, 131, 206, 1, 0, 86, 19, 1, 0, 91, 1, 0, 0, 81, 65, 87, 66, 182, 63, 204, 13, 148, 8, 2, 54, 233, 57, 191, 57, 208, 57, 134, 57, 49, 57, 82, 57, 28, 58, 153, 59, 138, 65, 89, 102, 0, 0, 0, 0, 79, 19, 92, 16, 11, 11, 147, 8, 186, 57, 238, 57, 135, 57, 201, 56, 44, 57, 141, 58, 204, 59, 47, 61, 230, 64, 244, 81, 249, 108, 0, 0, 225, 21, 63, 15, 56, 42, 105, 10, 41, 37, 158, 58, 16, 58, 61, 57, 215, 57, 69, 59, 241, 60, 209, 61, 50, 64, 202, 70, 79, 82, 196, 103, 143, 53, 226, 21, 254, 18, 74, 22, 55, 27, 251, 58, 103, 58, 249, 57, 148, 59, 159, 59, 180, 60, 137, 62, 204, 63, 207, 63, 191, 68, 208, 70, 60, 27, 23, 25, 185, 24, 116, 11, 225, 44, 31, 59, 167, 31, 197, 6, 84, 55, 207, 60, 187, 60, 251, 60, 158, 16, 196, 10, 133, 25, 20, 63, 98, 27, 101, 16, 91, 23, 64, 23, 103, 60, 219, 59, 75, 8, 3, 36, 89, 13, 176, 63, 183, 61, 72, 40, 214, 15, 35, 25, 127, 8, 222, 58, 32, 10, 218, 14, 247, 19, 223, 53, 226, 60, 9, 61, 193, 20, 222, 24, 180, 44, 240, 84, 206, 66, 174, 41, 225, 19, 147, 13, 79, 14, 75, 57, 228, 11, 52, 14, 247, 78, 121, 65, 182, 61, 26, 62, 175, 34, 74, 23, 76, 68, 163, 90, 112, 71, 180, 59, 97, 24, 129, 23, 190, 27, 117, 58, 232, 12, 219, 15, 109, 86, 254, 70, 182, 65, 246, 74, 141, 30, 255, 20, 233, 62, 59, 65, 168, 62, 127, 65, 81, 17, 236, 15, 206, 22, 199, 59, 42, 19, 35, 20, 118, 74, 230, 57, 61, 66, 21, 83, 145, 22, 171, 13, 70, 73, 130, 75, 49, 72, 47, 88, 209, 21, 84, 10, 110, 28, 122, 52, 65, 33, 167, 55, 97, 97, 162, 62, 137, 48, 31, 46, 37, 14, 69, 13, 81, 37, 67, 86, 230, 57, 113, 47, 167, 34, 127, 5, 18, 27, 115, 30, 228, 68, 88, 68, 74, 85, 161, 60, 107, 28, 78, 19, 3, 17, 123, 17, 129, 18, 202, 25, 254, 31, 100, 23, 195, 28, 0, 11, 74, 29, 109, 27, 62, 64, 42, 63, 130, 68, 144, 92, 116, 9, 88, 16, 61, 16, 67, 16, 62, 13, 107, 12, 120, 24, 25, 20, 85, 16, 120, 19, 48, 30, 28, 16, 59, 47, 101, 59, 244, 76, 190, 72, 163, 9, 246, 19, 126, 16, 154, 20, 139, 9, 38, 16, 57, 47, 208, 23, 41, 12, 1, 20, 221, 25, 221, 19, 238, 54, 87, 41, 247, 74, 231, 40, 128, 10, 47, 16, 41, 16, 115, 11, 10, 7, 79, 13, 92, 30, 40, 27, 161, 9, 68, 17, 35, 34, 7, 14, 136, 11, 55, 37, 220, 45, 133, 10, 149, 7, 204, 16, 166, 12, 21, 11, 85, 8, 180, 15, 201, 11, 81, 22, 15, 6, 167, 11, 55, 41, 246, 14, 12, 124, 146, 27, 34, 18, 153, 107, 217, 114, 47, 114, 101, 114, 31, 114, 212, 112, 105, 112, 7, 114, 226, 116, 216, 125, 211, 200, 0, 0, 0, 0, 185, 38, 194, 28, 146, 20, 112, 18, 1, 114, 93, 114, 72, 113, 247, 111, 181, 112, 204, 114, 82, 117, 74, 119, 198, 125, 24, 159, 82, 213, 0, 0, 190, 42, 89, 27, 35, 75, 38, 19, 75, 73, 52, 115, 7, 114, 16, 113, 223, 113, 153, 116, 211, 119, 192, 120, 153, 124, 211, 136, 3, 159, 164, 204, 227, 93, 81, 38, 74, 32, 236, 39, 41, 53, 21, 116, 120, 114, 207, 113, 114, 116, 138, 117, 43, 119, 205, 121, 198, 123, 108, 123, 104, 131, 176, 134, 243, 45, 106, 42, 175, 42, 205, 19, 165, 87, 186, 115, 46, 63, 106, 14, 81, 108, 51, 119, 250, 118, 159, 118, 57, 34, 207, 21, 5, 50, 120, 118, 85, 46, 206, 26, 135, 39, 220, 41, 246, 117, 23, 117, 158, 15, 229, 60, 251, 26, 241, 124, 92, 120, 101, 79, 240, 25, 110, 42, 85, 16, 227, 109, 119, 18, 241, 24, 237, 34, 197, 103, 55, 118, 245, 118, 206, 36, 80, 39, 58, 89, 91, 172, 100, 131, 218, 81, 153, 32, 186, 22, 137, 26, 161, 106, 236, 19, 19, 27, 67, 160, 29, 129, 6, 121, 33, 120, 215, 60, 181, 37, 64, 130, 232, 181, 78, 141, 52, 116, 118, 40, 113, 38, 88, 48, 248, 109, 53, 21, 61, 30, 191, 176, 110, 141, 117, 129, 161, 148, 149, 55, 139, 33, 189, 119, 164, 125, 61, 121, 148, 127, 98, 28, 22, 27, 102, 41, 50, 111, 229, 36, 113, 39, 49, 145, 176, 110, 23, 120, 78, 130, 207, 39, 100, 25, 107, 139, 91, 147, 28, 139, 209, 180, 63
    exif:WhiteBalance: 0
    exif:XResolution: 72/1
    exif:YCbCrPositioning: 1
    exif:YResolution: 72/1
    jpeg:colorspace: 2
    jpeg:sampling-factor: 2x2,1x1,1x1
    signature: 35a6f8a78c893c1df62cdb7f696d656045fb0962982cd0b7dd9854c4f4e6d556
  Profiles:
    Profile-exif: 21957 bytes
  Artifacts:
    filename: index.jpeg
    verbose: true
  Tainted: False
  Filesize: 2.756MB
  Number pixels: 7.99M
  Pixels per second: 57.07MB
  User time: 0.130u
  Elapsed time: 0:01.140
  Version: ImageMagick 6.8.9-9 Q16 x86_64 2019-06-15 http://www.imagemagick.org
-----------------------------------------------------------------------
Convert rgb to grayscale 
a.out  exp1.c  gray.jpeg  index.jpeg  stb_image.h  stb_image_write.h
-----------------------------------------------------------------------
Convert rgb to negetive 
a.out	gray.jpeg   stb_image.h        test_negate.jpeg
exp1.c	index.jpeg  stb_image_write.h
-----------------------------------------------------------------------
Convert rgb to black and white with threshold 
a.out		  exp1.c     index.jpeg   stb_image_write.h
black_white.jpeg  gray.jpeg  stb_image.h  test_negate.jpeg
-----------------------------------------------------------------------
Convert jpeg to png 
a.out		  exp1.c     index.jpeg  stb_image.h	    test_negate.jpeg
black_white.jpeg  gray.jpeg  index.png	 stb_image_write.h
students@CE-Lab-602-U12:~/Downloads/exp1$ 


*/
