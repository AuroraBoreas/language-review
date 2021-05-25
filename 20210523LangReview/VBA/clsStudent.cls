option explicit

implements clsPerson

private m_name as string
private m_age as integer
private m_id as integer

public sub init(name as string, age as integer, id as integer)
    m_name = name
    m_age = age
    m_id = id
end sub

public function clsPerson_ToString() as string
    clsPerson_ToString = "name: " & m_name & ", age: " & m_age & ", id: " & m_id
end function