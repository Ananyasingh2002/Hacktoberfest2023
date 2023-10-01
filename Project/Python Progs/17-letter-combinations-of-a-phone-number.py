class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return 
        refer = {
            '2' : 'abc',
            '3' : 'def',
            '4' : 'ghi',
            '5' : 'jkl',
            '6' : 'mno',
            '7' : 'pqrs',
            '8' : 'tuv',
            '9' : 'wxyz'
        }
        res = []
        def find_combo(temp_res, digits):
            if not digits:
                res.append(temp_res)
                return
            
            for i in refer[digits[0]]:
                find_combo(temp_res+i, digits[1:])
        
        find_combo('', digits)
        return res
