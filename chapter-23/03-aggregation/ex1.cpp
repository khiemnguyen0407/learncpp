/* Aggregation Demonstration */

/* Let’s take a look at a Teacher and Department example in more detail. In this example, we're 
going to make a couple of simplifications: First, the department will only hold one teacher. 
Second, the teacher will be unaware of what department they're part of.
*/

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Teacher
{
private:
  std::string name{};

public:
    Teacher(std::string_view name="")
        : name { name }
    {
    }

  const std::string& get_name() const { return this->name; }
  void set_name(std::string_view name) { this->name = name; }
};

class Department
{
private:
    std::vector<Teacher> teachers;

public:
    Department(std::vector<Teacher>& teachers) : teachers { teachers }
    {
    }

    void add_employee(Teacher& teacher) {
        teachers.push_back(teacher);
    }

    std::vector<Teacher> get_teachers() {
        return this->teachers;
    }
};

int main()
{
    // Create a teacher outside the scope of the Department
    Teacher bob{ "Scott" }; // create a teacher
    Teacher frank { "Euan" };
    std::vector<Teacher> teachers = {bob, frank};

    Teacher khiem { "Khiem" };
    Teacher cameron { "Cameron" };
    Teacher agnes { "Agnes" };
    {
        // Create a department and use the constructor parameter to pass
        // the teacher to it.
        Department dept {teachers};
        dept.add_employee(khiem);
        dept.add_employee(cameron);
        dept.add_employee(agnes);

        std::vector<Teacher> dept_teachers = dept.get_teachers();
        for (int i {0}; i < dept_teachers.size(); ++i) {
            std::cout << dept_teachers[i].get_name() << " works in the department.\n";
        }

    } // department goes out of scope here and is destroyed

    // bob still exists here, but the department doesn't
    std::cout << "===========================\n";
    std::cout << "Department is gone but\n";
    std::cout << bob.get_name() << " still exists!\n";
    std::cout << frank.get_name() << " still exists!\n";
  return 0;
}