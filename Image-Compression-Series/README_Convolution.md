This is a c++ program for Image Compression.
I have used the Convolution method to compress the Image.
In this method, I have used a kernal of size 3x3.
I have direactly used the pixel values of the image.
And  after applying the Convolution operation to those pixel values, i got a new set of values which are the pixel values of the compressed Image.

====================================================================================================================================================

In this code i have used two functions the first one is printSubMatrix and second one is Convolution, the first function is used to print the submatrix of the matrix of the pixel values of the original image, showing us how kermal is going to slide over the original set of pixel values, and then there is convolution function which is used for convolution operation.

The pixel values I get after applying the convolution opeartion are as follow:

{{36 43 50 97 129 170 169},
{34 44 54 117 150 190 177},
{28 38 49 104 140 173 160},
[41 49 57 100 130 160 157},
[48 56 63 106 140 173 170},
{48 56 63 106 140 173 170},
{30 37 45 85 119 152 151},
{30 37 45 85 119 152 151},
{30 37 45 85 119 152 151},
{34 45 56 110 150 186 173},
{30 37 45 85 119 152 151},
{30 34 38 77 113 150 151},
{31 35 40 72 99 136 147},
{36 43 50 97 129 170 169},
{34 44 54 117 150 190 177},
{28 38 49 104 140 173 160},
{41 49 57 100 130 160 157},
{48 56 63 106 140 173 170},
{48 56 63 106 140 173 170},
{30 37 45 85 119 152 151},
{30 37 45 85 119 152 151},
{30 37 45 85 119 152 151},
{34 45 56 110 150 186 173},
{30 37 45 85 119 152 151}}

=================================================================================================================================================
This is the compressed Image.
![Compressed Image](https://github.com/SHIVAMAMBAH/CPP-Projects/assets/106507443/801f6d35-3daa-4b4a-8752-de6e20fdccfe)
