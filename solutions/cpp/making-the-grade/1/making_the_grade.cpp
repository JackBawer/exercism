#include <array>
#include <cmath>
#include <cstddef>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // TODO: Implement round_down_scores
    std::vector<int> res {};
    for (std::size_t i = 0; i < student_scores.size(); ++i) {
        res.push_back(static_cast<int>(student_scores[i]));
    }
    return res;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // TODO: Implement count_failed_students
    int failed_students_num{};
    for (const auto& s: student_scores) {
        if (s <= 40) ++failed_students_num;
    }
    return failed_students_num;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // TODO: Implement letter_grades
    int increment{ (highest_score - 40) / 4};
    std::array<int, 4> lower_thresholds{};
    lower_thresholds[0] = 41;
    for (std::size_t i{ 1 }; i < 4; ++i) {
        lower_thresholds[i] = lower_thresholds[i - 1] + increment;
    }
    return lower_thresholds;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement student_ranking
    std::vector<std::string> ranking{ };
    for (std::size_t i{ 0 }; i < student_scores.size(); ++i) {
        ranking.push_back(std::to_string(i + 1) + ". " + student_names[i] + ": " 
                          + std::to_string(student_scores[i]));
    }
    return ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    // TODO: Implement perfect_score
    for (std::size_t i{ 0 }; i < student_names.size(); ++i) {
        if (student_scores[i] == 100) return student_names[i];
    }
    return "";
}
