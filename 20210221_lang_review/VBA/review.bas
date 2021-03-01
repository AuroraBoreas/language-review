option explicit

public sub Main()

    ' variable
    ' data types
    ' type conversion
    ' function
    ' statement
    ' control flow
    ' loop
    ' class
    call TestPersonClass()
    ' container
    ' fileIO

end sub


private sub TestPersonClass()
    Dim p As New clsPerson
    p.init "ZL", "male", 34
    
    Debug.Print p.ToString()
    set p = nothing

end sub