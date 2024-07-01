#include <opencv2/opencv.hpp>
#include <string>

void create_id_card(const std::string& student_name, const std::string& student_id, const std::string& school_name, const std::string& output_path) {
    // Dimensions of the ID card
    int width = 400;
    int height = 250;
    cv::Scalar background_color(255, 255, 255); // white
    cv::Scalar text_color(0, 0, 0); // black

    // Create a blank image with white background
    cv::Mat image(height, width, CV_8UC3, background_color);

    // Define positions for the text
    cv::Point school_name_position(20, 40);
    cv::Point student_name_position(20, 120);
    cv::Point student_id_position(20, 180);
    cv::Rect logo_rect(300, 20, 80, 80);

    // Set the font
    int font_face = cv::FONT_HERSHEY_SIMPLEX;
    double font_scale = 0.8;
    int thickness = 2;

    // Put text on the image
    cv::putText(image, school_name, school_name_position, font_face, font_scale, text_color, thickness);
    cv::putText(image, "Name: " + student_name, student_name_position, font_face, font_scale, text_color, thickness);
    cv::putText(image, "ID: " + student_id, student_id_position, font_face, font_scale, text_color, thickness);

    // Draw a rectangle for the logo
    cv::rectangle(image, logo_rect, text_color, thickness);
    cv::putText(image, "Logo", cv::Point(logo_rect.x + 15, logo_rect.y + 50), font_face, font_scale, text_color, thickness);

    // Save the image
    cv::imwrite(output_path, image);
    std::cout << "ID card created for " << student_name << " and saved to " << output_path << std::endl;
}

int main() {
    struct Student {
        std::string name;
        std::string id;
        std::string school;
    };

    std::vector<Student> students = {
        {"John Doe", "123456", "XYZ High School"},
        {"Jane Smith", "789012", "XYZ High School"}
    };

    for (const auto& student : students) {
        std::string output_file = "id_card_" + student.id + ".png";
        create_id_card(student.name, student.id, student.school, output_file);
    }

    return 0;
}
