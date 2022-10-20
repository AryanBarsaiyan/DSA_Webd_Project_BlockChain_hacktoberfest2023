class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0: 
			return 'Zero'
        ds1 = [1000000000, 1000000, 1000, 100]
        ws1 = ['Billion', 'Million', 'Thousand', 'Hundred']
        ds2 = [90, 80, 70, 60, 50, 40, 30, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
        ws2 = ['Ninety', 'Eighty', 'Seventy', 'Sixty', 'Fifty', 'Forty', 'Thirty', 'Twenty', 
               'Nineteen', 'Eighteen', 'Seventeen', 'Sixteen', 'Fifteen', 'Fourteen', 'Thirteen', 'Twelve', 'Eleven','Ten',
               'Nine', 'Eight', 'Seven', 'Six', 'Five', 'Four', 'Three', 'Two', 'One'] 
        i = 0
        ls = []
        while i < len(ds1):
            if num >= ds1[i]:
                num1, num = divmod(num, ds1[i])
                if num1:
                    ls.append(self.numberToWords(num1))
                    ls.append(ws1[i]) 
            i += 1
        i = 0
        while num:
            if num < ds2[i]:
                i += 1
            else:
                num -= ds2[i]
                ls.append(ws2[i])
        return ' '.join(ls)
