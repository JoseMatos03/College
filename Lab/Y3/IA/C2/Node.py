
class Node:
    def __init__(self, name: str, id: int =-1) -> None:
        self.m_id = id
        self.m_name = str(name)

    def __str__(self) -> str:
        return "Node: " + self.m_name

    def __repr__(self) -> str:
        return self.__str__()

    def setId(self, id: int) -> None:
        self.m_id = id

    def getId(self) -> int:
        return self.m_id

    def getName(self) -> str:
        return self.m_name

    def __eq__(self, value: object) -> bool:
        return self.m_name == value.m_name

    def __hash__(self) -> int:
        return hash(self.m_name)