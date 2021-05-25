Option Explicit

Public Sub test_person()
    Dim p1 As New clsTeacher
    p1.init "TS", 30, "Japanese"
    
    Dim s1 As New clsStudent
    s1.init "ZL", 35, 1
    
    Dim persons As New Collection
    persons.Add p1
    persons.Add s1
    
    Dim person As clsPerson
    Debug.Print vbNewLine & "--- collection ---"
    For Each person In persons
        Debug.Print person.ToString()
    Next
    
    Dim ppl(5) As clsPerson
    Set ppl(0) = p1
    Set ppl(1) = s1

    Dim i As Integer
    Debug.Print vbNewLine & "--- array ---"
    For i = 0 To 5
        If Not ppl(i) Is Nothing Then
            Debug.Print ppl(i).ToString()
        End If
    Next i
End Sub
