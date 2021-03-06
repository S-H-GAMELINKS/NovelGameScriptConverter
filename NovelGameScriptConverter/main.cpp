// NovelGameScriptConverter
// Create by S.H.

// include Boost library
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

namespace fs = boost::filesystem;

// include openCV
#include <opencv2/opencv.hpp>

// One (and only one) of your C++ files must define CVUI_IMPLEMENTATION
// before the inclusion of cvui.h to ensure its implementaiton is compiled.
#define CVUI_IMPLEMENTATION
#include "cvui.h"

// Hide Console Window
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

// Set Software Title
constexpr const char* WindowName = "NovelGameScriptConverter";

//Read All Script File Path
std::vector<std::string> AllFilePath() {

	std::vector<std::string> Container;

	std::string Path = "text";

	const fs::path path(Path);

	BOOST_FOREACH(const fs::path& p, std::make_pair(fs::directory_iterator(path),
		fs::directory_iterator())) {
		if (!fs::is_directory(p))
			Container.emplace_back(std::move(p.filename().string()));
	}

	return Container;
}

void DrawButton(cv::Mat frame) {

	if (cvui::button(frame, 20, 40, "LINKS"))
		std::cout << "LINKS" << std::endl;

	if (cvui::button(frame, 20, 70, "TyranoScript"))
		std::cout << "TyranoScript" << std::endl;

	if (cvui::button(frame, 20, 100, "Nscripter"))
		std::cout << "Nscripter" << std::endl;

	if (cvui::button(frame, 20, 130, "KAG/Kirikiri"))
		std::cout << "KAG/Kirikiri" << std::endl;
}

int main(){

	// Create a frame where components will be rendered to.
	cv::Mat frame = cv::Mat(380, 480, CV_8UC3);

	// Init cvui and tell it to create a OpenCV window, i.e. cv::namedWindow(WINDOW_NAME).
	cvui::init(WindowName);

	while (true) {
		// Fill the frame with a nice color
		frame = cv::Scalar(49, 52, 49);

		// Draw Convert Button
		DrawButton(frame);

		// Update cvui stuff and show everything on the screen
		cvui::imshow(WindowName, frame);

		// Exit to ESC Key!
		if (cv::waitKey(20) == 27) {
			break;
		}
	}

    return 0;
}

