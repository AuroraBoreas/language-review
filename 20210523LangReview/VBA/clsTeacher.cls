Option Explicit

Implements clsPerson

Private m_name As String
Private m_age As Integer
Private m_subject As String

Sub init(ByVal name As String, ByVal age As Integer, ByVal subject As String)
    m_name = name
    m_age = age
    m_subject = subject
End Sub

Public Property Get name() As String
    name = m_name
End Property

Public Property Let name(ByVal name As String)
    m_name = name
End Property

Public Property Get age() As Integer
    age = m_age
End Property

Public Property Let age(ByVal age As Integer)
    m_age = age
End Property

Public Property Get subject() As String
    subject = m_subject
End Property

Public Property Let subject(ByVal subject As String)
    m_subject = subject
End Property

' implements interface;
' ! method_name is important
Public Function clsPerson_ToString() As String
    clsPerson_ToString = "name: " & m_name & ", age: " & m_age & "subject: " & m_subject
End Function
