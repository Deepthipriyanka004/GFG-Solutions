<<<<<<< HEAD
class Solution:
    def dataTypeSize(self, str):
        # Code here
        data_types= {"Character":1, "Integer":4, "Float": 4, "Double": 8, "Long": 8}

        if str in data_types:
=======
class Solution:
    def dataTypeSize(self, str):
        # Code here
        data_types= {"Character":1, "Integer":4, "Float": 4, "Double": 8, "Long": 8}

        if str in data_types:
>>>>>>> ad739313e242f91283e5cc26895db2ac31e1585c
            return data_types.get(str)