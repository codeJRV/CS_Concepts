#include <iostream>
#include <string>
#include <unordered_map>

void insertionSort(int Arr[], int n)
{
    int i, key, j;
    for( i =1; i< n; i++)
    {
        key = arr[i];
        j = i -1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j = j -1;

        }
        arr[j+1] = key;
    }
}


int main()
{
    // Create an unordered_map of three strings (that map to strings)
    std::unordered_map<std::string, std::string> u = {
            {"RED","#FF0000"},
            {"GREEN","#00FF00"},
            {"BLUE","#0000FF"}
    };

    // Iterate and print keys and values of unordered_map
    for( const auto& n : u ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }

    // Add two new entries to the unordered_map
    u["BLACK"] = "#000000";
    u["WHITE"] = "#FFFFFF";

    // Output values by key
    std::cout << "The HEX of color RED is:[" << u["RED"] << "]\n";
    std::cout << "The HEX of color BLACK is:[" << u["BLACK"] << "]\n";

    //remove an element from an unordered map


    return 0;
}