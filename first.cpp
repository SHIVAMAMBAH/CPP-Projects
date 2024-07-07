#include<iostream>
#include<vector>
#include<cmath>
#include<thread>
#include<future>


static void printpixelvalues(const std::vector<std::vector<std::vector<int>>>& vec3D, int colorIndex, const std::string& colorName) 
{
	std::cout << "Values of " << colorName << " Pixels" << "\n";
	for (const auto& first : vec3D) 
	{
		for (const auto& second : first) 
		{
			std::cout << second[colorIndex] << " ";
		}
		std::cout << "\n";
	}
}

static void printElements(const std::vector<std::vector<std::vector<int>>> vec3D) 
{
	for (const auto& first : vec3D)
	{
		for (const auto& second : first)
		{
			for (const auto& third : second)
			{
				std::cout << third << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}
}

static int ImageSize(const std::vector<std::vector<std::vector<int>>> vec3D) {
	return vec3D.size() * vec3D[0].size() * vec3D[0][0].size();
}

static void Filter(std::vector<std::vector<std::vector<int>>> vec3D,double alpha, int colorCode)
{
	double one_minus_alpha = 1 - alpha;
	std::cout << "values after Filter"<<"\n";
	for (int i = 0; i < vec3D.size(); i++)
	{
		for (int j = 0; j < vec3D[0].size(); j++)
		{
			switch (colorCode) {
				case 0:
					vec3D[i][j][0] = static_cast<int>(std::floor(vec3D[i][j][0] + alpha * (255 - vec3D[i][j][0])));
					vec3D[i][j][1] = static_cast<int>(std::floor(vec3D[i][j][1] * (one_minus_alpha)));
					vec3D[i][j][2] = static_cast<int>(std::floor(vec3D[i][j][2] * (one_minus_alpha)));
					break;
				case 1:
					vec3D[i][j][0] = static_cast<int>(std::floor(vec3D[i][j][0]* (one_minus_alpha)));
					vec3D[i][j][1] = static_cast<int>(std::floor(vec3D[i][j][1] + alpha*(255 - vec3D[i][j][1])));
					vec3D[i][j][2] = static_cast<int>(std::floor(vec3D[i][j][2] * (one_minus_alpha)));
					break;
				case 2:
					vec3D[i][j][0] = static_cast<int>(std::floor(vec3D[i][j][0]* (one_minus_alpha)));
					vec3D[i][j][1] = static_cast<int>(std::floor(vec3D[i][j][1] * (one_minus_alpha)));
					vec3D[i][j][2] = static_cast<int>(std::floor(vec3D[i][j][2] + alpha* (255 - vec3D[i][j][2])));
					break;
				default:
					std::cout << "Invalid colorCode Number(Pleasse choose among 0,1 and 2)" << "\n";
					break;
			}
		}
	}

	printElements(vec3D);
}

static void Brightness(std::vector<std::vector<std::vector<int>>> vec3D, int brightnessFactor) 
{
	for (int i = 0; i < vec3D.size(); i++)
	{
		for (int j = 0; j < vec3D[0].size(); j++)
		{
			vec3D[i][j][0] = vec3D[i][j][0]+brightnessFactor;
			vec3D[i][j][1] = vec3D[i][j][1]+brightnessFactor;
			vec3D[i][j][2] = vec3D[i][j][2]+brightnessFactor;
		}
	}

	printElements(vec3D);
}


namespace Contrast {

	namespace {
		static int averageIntensity(std::vector<std::vector<std::vector<int>>> vec3D) {
			int sumOfPixels = 0;
			for (const auto& first : vec3D)
			{
				for (const auto& second : first)
				{
					for (const auto& third : second)
					{
						sumOfPixels += third;
					}
					std::cout << "\n";
				}
				std::cout << "\n";
			}
			int size = ImageSize(vec3D);
			return  static_cast<int>(std::floor(sumOfPixels / size));
		}
	}
	static void IncreasingContrast(std::vector<std::vector<std::vector<int>>> vec3D,double ContrastFactor) {
		int mean = averageIntensity(vec3D);

		for (int i = 0; i < vec3D.size(); i++)
		{
			for (int j = 0; j < vec3D[0].size(); j++)
			{
				vec3D[i][j][0] = mean + ContrastFactor*(vec3D[i][j][0]-mean);
				vec3D[i][j][1] = mean + ContrastFactor*(vec3D[i][j][1]-mean);
				vec3D[i][j][2] = mean + ContrastFactor*(vec3D[i][j][2]-mean);
			}
		}
		std::cout << "Increasing Contrast Function" << "\n";
		for (const auto& first : vec3D)
		{
			for (const auto& second : first)
			{
				for (const auto& third : second)
				{
					if (third < 0) {
						std::cout << 0 << " ";
					}
					else {
						std::cout << third << " ";
					}
				}
				std::cout << "\n";
			}
			std::cout << "\n";
		}
	}

	static void DecreasingContrast(std::vector<std::vector<std::vector<int>>> vec3D,double ContrastFactor) {
		int mean = averageIntensity(vec3D);

		for (int i = 0; i < vec3D.size(); i++)
		{
			for (int j = 0; j < vec3D[0].size(); j++)
			{
				vec3D[i][j][0] = mean + ContrastFactor * (vec3D[i][j][0] - mean);
				vec3D[i][j][1] = mean + ContrastFactor * (vec3D[i][j][1] - mean);
				vec3D[i][j][2] = mean + ContrastFactor * (vec3D[i][j][2] - mean);
			}
		}
		std::cout << "Decreasing Contrast Function" << "\n";
		for (const auto& first : vec3D)
		{
			for (const auto& second : first)
			{
				for (const auto& third : second)
				{
					if (third < 0) {
						std::cout << 0 << " ";
					}
					else {
						std::cout << third << " ";
					}
				}
				std::cout << "\n";
			}
			std::cout << "\n";
		}
	}
}

static void GrayScale(std::vector<std::vector<std::vector<int>>> vec3D) 
{
	int rows = vec3D.size();
	int columns = vec3D[0].size();

	std::cout << "GrayScale Values" << "\n";
	std::vector<std::vector<int>> vec2D(rows,std::vector<int>(columns));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			
			vec2D[i][j] = static_cast<int>(std::floor(0.2989*vec3D[i][j][0] + 0.5870*vec3D[i][j][1] + 0.1140*vec3D[i][j][2]));
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{

			std::cout << vec2D[i][j] << " ";
		}
		std::cout << "\n";
	}
}

static void ColorInversion(std::vector<std::vector<std::vector<int>>> vec3D)
{
	
	for (int i = 0; i < vec3D.size(); i++)
	{
		for (int j = 0; j < vec3D[0].size(); j++)
		{
			vec3D[i][j][0] = 255-vec3D[i][j][0];
			vec3D[i][j][1] = 255-vec3D[i][j][1];
			vec3D[i][j][2] = 255-vec3D[i][j][2];
		}
	}
	std::cout << "Color Inversion" << "\n";

	printElements(vec3D);
}


int main()
{
	std::vector<std::vector<std::vector<int>>> vec3D =
	{ {{12,13,14},{21,31,41},{11,33,44},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{22,23,24},{21,31,41},{17,83,54},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{92,93,94},{71,51,49},{91,23,74},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{12,13,14},{21,31,41},{11,33,44},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{22,23,24},{21,31,41},{17,83,54},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{92,93,94},{71,51,49},{91,23,74},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{12,13,14},{21,31,41},{11,33,44},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{22,23,24},{21,31,41},{17,83,54},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{92,93,94},{71,51,49},{91,23,74},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{12,13,14},{21,31,41},{11,33,44},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{22,23,24},{21,31,41},{17,83,54},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{92,93,94},{71,51,49},{91,23,74},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{12,13,14},{21,31,41},{11,33,44},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{22,23,24},{21,31,41},{17,83,54},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{92,93,94},{71,51,49},{91,23,74},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{12,13,14},{21,31,41},{11,33,44},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{22,23,24},{21,31,41},{17,83,54},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{92,93,94},{71,51,49},{91,23,74},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{12,13,14},{21,31,41},{11,33,44},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{22,23,24},{21,31,41},{17,83,54},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{92,93,94},{71,51,49},{91,23,74},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{12,13,14},{21,31,41},{11,33,44},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{22,23,24},{21,31,41},{17,83,54},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{92,93,94},{71,51,49},{91,23,74},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{12,13,14},{21,31,41},{11,33,44},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{22,23,24},{21,31,41},{17,83,54},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{92,93,94},{71,51,49},{91,23,74},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{12,13,14},{21,31,41},{11,33,44},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{22,23,24},{21,31,41},{17,83,54},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}},
	  {{92,93,94},{71,51,49},{91,23,74},{31,34,67},{12,13,14},{21,31,41},{11,33,44},{31,34,67}} 
	};;

	std::thread t1([vec3D]() {printElements(vec3D); });
	t1.join();
	
	std::cout<<ImageSize(vec3D)<<"\n";

	std::thread pixelThreadZero([vec3D]() {printpixelvalues(vec3D, 0, "Red"); });
	pixelThreadZero.join();
	
	std::thread pixelThreadOne([vec3D]() {printpixelvalues(vec3D, 1, "Blue"); });
	pixelThreadOne.join();
	
	std::thread pixelThreadTwo([vec3D]() {printpixelvalues(vec3D, 2, "Green"); });
	pixelThreadTwo.join();
	

	std::thread filterThreadOne([vec3D]() {Filter(vec3D, 0.8, 0);});
	filterThreadOne.join();

	std::thread filterThreadTwo([vec3D]() {Filter(vec3D, 0.8, 1);});
	filterThreadTwo.join();
	
	std::thread filterThreadThree([vec3D]() {Filter(vec3D, 0.8, 2);});
	filterThreadThree.join();

	std::thread brightnessThread([vec3D]() {Brightness(vec3D, 30);});
	brightnessThread.join();

	std::thread IncreasingContrastThread([vec3D]() {Contrast::IncreasingContrast(vec3D, 1.5); });
	IncreasingContrastThread.join();
	
	std::thread DecreasingContrastTHread([vec3D]() {Contrast::DecreasingContrast(vec3D, 0.2); });
	DecreasingContrastTHread.join();

	std::thread GrayScaleTHread([vec3D]() {GrayScale(vec3D); });
	GrayScaleTHread.join();

	std::thread ColorInversionThread([vec3D]() {ColorInversion(vec3D); });
	ColorInversionThread.join();

	return 0;
}