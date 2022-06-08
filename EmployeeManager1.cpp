class Permanent
{
  private:
    char name[20];
    int salary;
  public:
    Permanent(char* _name, int sal);
    const char* GetName();
    int GetPay();
};

Permanent::Permanent(char* _name, int sal){
  strcpy(name, _name);
  salary=sal;
}
const char* Permanent::GetName(){
  return name;
}
int Permanent::GetPay(){
  return salary;
}

class Department
{
  Permanent* empList[10];
  int index;
  public:
    Department(): index(0) {};
    void AddEmployee(Permanent* emp);
    void ShowList();
};
void Department::AddEmployee(Permanent* emp)
{
  empList[index++]=emp;
}
void Department::ShowList()
{
  for(int i=0; i<index; i++)
  {
    cout<<"name: "<<empList[i]->GetName()<<endl;
    cout<<"salary: "<<empList[i]->GetPay()<<endl;
    cout<<endl;
  }
}

int main()
{
  Department department;
  
  department.AddEmployee(new Permanent("KIM", 1000));
  department.AddEmployee(new Permanent("LEE", 1500));
  department.AddEmployee(new Permanent("JUN", 2000));
  
  department.ShowList();
  return 0;
}
