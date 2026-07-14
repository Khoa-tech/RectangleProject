/**
 * @file main.cpp
 * @brief Chương trình quản lý danh sách các đối tượng hình chữ nhật (Rectangle) 
 * và tự động phát sinh tài liệu kỹ thuật.
 * @author Bạn của bạn (AI Collaborator)
 * @date 2026-07-14
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

/**
 * @class Rectangle
 * @brief Lớp biểu diễn một hình chữ nhật trong không gian hai chiều.
 * 
 * Lớp này hỗ trợ lưu trữ kích thước chiều rộng, chiều cao, tính toán chu vi,
 * diện tích và kiểm soát các giá trị đầu vào hợp lệ để tránh lỗi logic hình học.
 */
class Rectangle {
private:
    double width;  ///< Chiều rộng của hình chữ nhật (phải lớn hơn 0)
    double height; ///< Chiều cao của hình chữ nhật (phải lớn hơn 0)

public:
    /**
     * @brief Phương thức khởi tạo mặc định.
     * Khởi tạo một hình chữ nhật có kích thước mặc định là 1.0 x 1.0.
     */
    Rectangle() : width(1.0), height(1.0) {}

    /**
     * @brief Phương thức khởi tạo có tham số.
     * @param w Chiều rộng mong muốn.
     * @param h Chiều cao mong muốn.
     * @throws std::invalid_argument Nếu chiều rộng hoặc chiều cao truyền vào nhỏ hơn hoặc bằng 0.
     */
    Rectangle(double w, double h) {
        if (w <= 0.0 || h <= 0.0) {
            throw std::invalid_argument("Kích thước chiều rộng và chiều cao phải lớn hơn 0!");
        }
        width = w;
        height = h;
    }

    /**
     * @brief Lấy chiều rộng hiện tại.
     * @return Kiểu double - Giá trị chiều rộng.
     */
    double getWidth() const { return width; }

    /**
     * @brief Lấy chiều cao hiện tại.
     * @return Kiểu double - Giá trị chiều cao.
     */
    double getHeight() const { return height; }

    /**
     * @brief Tính chu vi của hình chữ nhật.
     * @details Công thức tính: @f$ P = (width + height) \times 2 @f$.
     * @return Kiểu double - Chu vi của hình chữ nhật.
     */
    double getPerimeter() const {
        return (width + height) * 2.0;
    }

    /**
     * @brief Tính diện tích của hình chữ nhật.
     * @details Công thức tính: @f$ S = width \times height @f$.
     * @return Kiểu double - Diện tích của hình chữ nhật.
     */
    double getArea() const {
        return width * height;
    }
};

/**
 * @brief Hàm khởi chạy chính của chương trình.
 * 
 * Tạo ra 9 đối tượng hình chữ nhật với các kích thước khác nhau, sau đó
 * lặp qua từng đối tượng để in chu vi và diện tích tương ứng ra màn hình.
 * 
 * @return int Mã trạng thái kết thúc chương trình (0 là thành công).
 */
int main() {
    try {
        // Tạo vector chứa 9 đối tượng Rectangle với các kích thước khác nhau
        std::vector<Rectangle> rects;
        for (int i = 1; i <= 9; ++i) {
            // Tạo kích thước tăng dần: (1x2), (2x3), (3x4), ..., (9x10)
            rects.push_back(Rectangle(static_cast<double>(i), static_cast<double>(i + 1)));
        }

        // In kết quả ra màn hình dưới dạng bảng
        std::cout << std::left 
                  << std::setw(10) << "Hình" 
                  << std::setw(15) << "Kích thước" 
                  << std::setw(15) << "Chu vi" 
                  << std::setw(15) << "Diện tích" << "\n";
        std::cout << std::string(55, '-') << "\n";

        for (size_t i = 0; i < rects.size(); ++i) {
            std::cout << std::left 
                      << std::setw(10) << (i + 1)
                      << std::setw(1) << rects[i].getWidth() << "x" << std::setw(13) << rects[i].getHeight()
                      << std::setw(15) << rects[i].getPerimeter()
                      << std::setw(15) << rects[i].getArea() << "\n";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Đã xảy ra lỗi: " << e.what() << "\n";
        return 1;
    }

    return 0;
}