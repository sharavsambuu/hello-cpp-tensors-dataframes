#include <DataFrame/DataFrame.h>                  // Main DataFrame header
#include <DataFrame/DataFrameFinancialVisitors.h> // Financial algorithms
#include <DataFrame/DataFrameMLVisitors.h>        // Machine-learning algorithms
#include <DataFrame/DataFrameStatsVisitors.h>     // Statistical algorithms
#include <DataFrame/Utils/DateTime.h>             // Cool and handy date-time object
#include <iostream>

// DataFrame library is entirely under hmdf name-space
//
using namespace hmdf;

// A DataFrame with ulong index type
//
using ULDataFrame = StdDataFrame<unsigned long>;

// A DataFrame with string index type
//
using StrDataFrame = StdDataFrame<std::string>;

// A DataFrame with DateTime index type
//
using DTDataFrame = StdDataFrame<DateTime>;

// This is just some arbitrary type to show how any type could be in DataFrame
//
struct MyData
{
    int i{10};
    double d{5.5};
    std::string s{"Some Arbitrary String"};

    MyData() = default;
};

int main()
{

    std::vector<unsigned long> idx_col1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<MyData> mydata_col(10);
    std::vector<int> int_col1 = {1, 2, -3, -4, 5, 6, 7, 8, 9, -10};
    std::vector<double> dbl_col1 = {0.01, 0.02, 0.03, 0.03, 0.05, 0.06, 0.03, 0.08, 0.09, 0.03};

    ULDataFrame ul_df1;

    ul_df1.load_index(std::move(idx_col1));
    ul_df1.load_column("dbl_col", std::move(dbl_col1));
    ul_df1.load_column("my_data_col", std::move(mydata_col));
    ul_df1.load_column("integers", std::move(int_col1));

    std::vector<unsigned long> idx_col2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<std::string> str_col = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
    std::vector<std::string> cool_col =
        {"Azadi", "Hello", " World", "!", "Hype", "cubic spline", "Shawshank", "Silverado", "Arash", "Pardis"};
    std::vector<double> dbl_col2 = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0};

    ULDataFrame ul_df2;

    // Also, you can load data into a DataFrame all at once.
    // In this case again the data is moved to the DataFrame.
    //
    ul_df2.load_data(std::move(idx_col2),
                     std::make_pair("string col", str_col),
                     std::make_pair("Cool Column", cool_col),
                     std::make_pair("numbers", dbl_col2));

    const auto &cool_col_ref = ul_df2.get_column<std::string>("Cool Column");
    const auto &str_col_ref = ul_df2.get_column<std::string>("string col");

    std::cout << cool_col_ref[1] << cool_col_ref[2] << cool_col_ref[3] << std::endl;
    std::cout << "Str Column = ";
    for (const auto &str : str_col_ref)
        std::cout << str << ", ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}