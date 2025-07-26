class Solution(object):
    def readBinaryWatch(self, turnedOn):
        if turnedOn < 0 or turnedOn > 10:
            return []
        
        result = []
        for h in range(12):
            for m in range(60):
                if bin(h).count('1') + bin(m).count('1') == turnedOn:
                    result.append("{}:{:02d}".format(h, m))
        
        return result