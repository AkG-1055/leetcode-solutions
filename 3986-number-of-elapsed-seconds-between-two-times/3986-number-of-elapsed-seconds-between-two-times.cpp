class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int end_HH = stoi(endTime.substr(0, 2));
        int end_MM = stoi(endTime.substr(3, 2));
        int end_SS = stoi(endTime.substr(6, 2));

        int endSeconds = end_HH * 3600 + end_MM * 60 + end_SS * 1;

        int start_HH = stoi(startTime.substr(0, 2));
        int start_MM = stoi(startTime.substr(3, 2));
        int start_SS = stoi(startTime.substr(6, 2));

        int startSeconds = start_HH * 3600 + start_MM * 60 + start_SS * 1;

        return endSeconds - startSeconds;
    }
};