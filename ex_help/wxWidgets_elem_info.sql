


what is: wxArrayString items_;
--> is is a class provided by 
the wxWidgets library for managing 
an array of strings. 
It s essentially a dynamic array (vector) of 
wxString objects

------------

 items_.push_back(drake_burner_->type_name());


 -----
  wxArraysString name_   idu zajedno sa
wxListBox -- unutra

    wxArrayString items_;
    wxListBox* listbox_units_ = nullptr;

-- wxDataViewListCtrl
    As for wxDataViewListCtrl, it is not directly equivalent
     to a standard C++ container. Instead, 
     it is a control provided by the wxWidgets library specifically
      for displaying tabular data. It allows you to create 
      a grid-like structure with rows and columns, making it
       suitable for presenting structured data in a user interface.




wxArrayString and std::vector almost equivalent
-------
wxArrayString items;
items.Add("String1");
items.Add("String2");

------------------------

std::vector<std::string> items;
items.push_back("String1");
items.push_back("String2");


------------------------

explain please:     //image
        wxImage::AddHandler(new wxPNGHandler);  // For PNG images
        wxImage image("../images/drake_burner.png", wxBITMAP_TYPE_PNG);
        wxBitmap bitmap(image);
        image_bitmap_ = new wxStaticBitmap(panel_, wxID_ANY, bitmap);

---
wxImage::AddHandler(new wxPNGHandler);: 
This line adds a handler for PNG images to the wxImage system. 
It tells the application how to handle PNG images. This is necessary to properly load PNG images.

wxImage image("../images/drake_burner.png", wxBITMAP_TYPE_PNG);: This line creates a wxImage
 object from the PNG image file located at "../images/drake_burner.png". The second argument, wxBITMAP_TYPE_PNG, specifies the image type.

wxBitmap bitmap(image);: This line converts the wxImage object (image) to a wxBitmap.
 A wxBitmap is a representation of an image that can be used by GUI controls.

image_bitmap_ = new wxStaticBitmap(panel_, wxID_ANY, bitmap);: 
This line creates a wxStaticBitmap control on the specified panel_ with the given ID (wxID_ANY) 
and sets its initial bitmap to the one created from the wxImage.


------------ fstream   VS   ofstream

td::ofstream: This is a specialization of std::ostream designed specifically for writing to files. 
It is used when you only need to perform output operations, and it simplifies the interface by focusing on writing.

Example:

cpp
Copy code
std::ofstream outputFile("example.txt");

In summary, if you need to perform both input and output 
operations on a file, you can use std::fstream. 
If you only intend to write to a file, you can use std::ofstream

-------------

--- ***************************************
--- wxWidget elements: -------------------------------------

can call "OnListKeyDown(wxKeyEvent& evt)" handler
void MainFrame::OnListKeyDown(wxKeyEvent& evt){
    switch (evt.GetKeyCode()) //-- is enum wxKeyCode-- is getter: GetKeyCode
        {
        case WXK_DELETE:
            DeleteSelectedTask();  
            break;   
        }
}
/-- perform Task:

void MainFrame::DeleteSelectedTask() {
    int selectedIndex = checkListBox->GetSelection();
    if(selectedIndex == wxNOT_FOUND) {
        return;
    }
    checkListBox->Delete(selectedIndex);

}

-- popular ENUM Keys:
--------------------
WXK_DELETE = 127
WXK_SPACE =32
WXK_TAB
 WXK_CONTROL_S,

WXK_CLEAR,
WXK_SHIFT,
WXK_ALT,

WXK_LEFT,
WXK_UP,
WXK_RIGHT,
WXK_DOWN,

---------------------------


-- common events used with "handler function":
------------
wxEVT_TEXT_ENTER, wxEVT_KEY_DOWN, wxEVT_BUTTON
wxEVT_CLOSE_WINDOW, wxEVT_MENU
wxEVT_LEFT_DOWN  -->mouse event
wxEVT_CHECKBOX
wxEVT_COMMAND_LISTBOX_SELECTED

addButton->Bind(wxEVT_BUTTON, &MainFrame::OnClickButtonAdd, this);
inputField->Bind(wxEVT_TEXT_ENTER, &MainFrame::OnEnterInput, this);
checkListBox->Bind(wxEVT_KEY_DOWN, &MainFrame::OnListKeyDown, this);
this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);
menuItem->Bind(wxEVT_MENU, &MainFrame::OnMenuItemSelected, this);


-- other events:
-- wxEVT_COMMAND_CHOICE_SELECTED, 
choiceCtrl->Bind(wxEVT_COMMAND_CHOICE_SELECTED, &MainFrame::OnChoiceSelected, this);


wxEVT_MOUSE_EVENTS (e.g., wxEVT_LEFT_DOWN, wxEVT_RIGHT_UP):

Various mouse events triggered when the user interacts with the mouse.
Useful for handling mouse clicks, movements, and other mouse-related actions.

Example:
someWindow->Bind(wxEVT_LEFT_DOWN, &MainFrame::OnLeftMouseDown, this);


-- for Board
Bind(wxEVT_PAINT, &Board::OnPaint, this);
Bind(wxEVT_KEY_DOWN, &Board::OnKeyDown, this);
Bind(wxEVT_TIMER, &Board::OnTimer, this);
-------------------------


----------GetCount() is a common method in wxWidgets controls that manage collections of items. 

--  wxCheckListBox:

int count = checkListBox->GetCount();
wxArrayString:

-- You can use GetCount() to get the number of strings in a wxArrayString.
wxArrayString myArray;
int count = myArray.GetCount();

wxListBox:
-- Similar to wxCheckListBox, wxListBox also has a GetCount() method to get the number of items.
int count = listBox->GetCount();

wxChoice:
-- The wxChoice control, representing a drop-down choice box, also provides GetCount() to get the number of items.
int count = choice->GetCount();


wxComboBox:
-- If you re using a combo box, you can use GetCount() to get the number of items in the drop-down list.
int count = comboBox->GetCount();


-- *********************************+

--  ->GetSelection()  method:

GetSelection() method is specific to controls that allow the selection of items, 
such as -- list boxes, check lists, and choice controls. 
It is not applicable to "wxArrayString" directly, as wxArrayString is a container
 for strings and does not have a concept of selection.
 wxListBox
 wxCheckListBox
 wxChoice
 wxComboBox
 --             int selectedIndex = checkListBox->GetSelection();


-- listBox   vs   chekListBox

-- listBox
wxListBox* listBox = new wxListBox(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, itemList, wxLB_SINGLE | wxLB_EXTENDED);
-- wxCheckListBox:
wxCheckListBox* checkListBox = new wxCheckListBox(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, itemList);


----------------------
wxArayString  --- equivalnet to --> std::vector <std::string>
----
Yes, it makes sense. wxArrayString is a class in wxWidgets that is similar
 to std::vector<std::string> in standard C++. The method push_back() is used with wxArrayString 
 just like it is used with std::vector<std::string>. The purpose is to add string elements to the array.

---


Yes, that s correct. If you create the wxStaticText control with the line:

hp_ = new wxStaticText(panel, wxID_ANY, "HP: some text title", wxPoint(0, 22), wxSize(800, 50));
The initial label for hp_ is set to "HP: some text title." If you later call:


hp_->SetLabel("HP: " + std::to_string(current_unit_->max_health()));

The label for the hp_ control will be updated to "HP: " followed by the value of current_unit_->max_health(). 
The initial label set during the control s creation will be replaced by the new label provided in the SetLabel



--- convert integer into string for static display:

MainFrame::MainFrame(const wxString& title):wxFrame(nullptr,wxID_ANY,title)
{        wxPanel* panel = new wxPanel(this);
             
        int intValue = 42;  // Replace this with your integer value
        wxString labelText = wxString::Format("Value: %d", intValue);
        wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, labelText, wxPoint(10, 10));
}



--------------------------------

            wxSize size = GetSize();
---> if i want to change the size of the window --like mihael
--------

GetSize() is a method that belongs to a wxWindow-derived class (like wxFrame or wxPanel)
wxSize size = GetSize(); gets the size of the window and assigns it to the size variable.
 After this line, you can use size to access the width and height of the window.

For example:
--
int width = size.GetWidth();
int height = size.GetHeight();


------------------------
 2 different aproac -- resault same


With wxListBox + .push_back()
items_.push_back(drake_burner_->type_name()); // took just one att from obj.
items_.push_back(dwarvish_fighter_->type_name());
items_.push_back(elvish_archer_->type_name());
listbox_units_ = new wxCheckListBox(panel_, wxID_ANY, wxPoint(0,0), wxSize(180,452), items_);



with wxCheckListBox + Insert():
-------------------------
//listbox
listbox_units_ = new wxCheckListBox(panel_, wxID_ANY, wxPoint(0,0), wxSize(180,452), items_);
items_.Insert(drake_burner_->type_name(), listbox_units_->GetCount()); // took just one att from obj.
items_.Insert(dwarvish_fighter_->type_name(), listbox_units_->GetCount());
items_.Insert(elvish_archer_->type_name(), listbox_units_->GetCount());
listbox_units_->Set(items_);
