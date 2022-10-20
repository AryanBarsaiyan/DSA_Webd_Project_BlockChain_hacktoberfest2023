class Solution:
    def containVirus(self, isInfected: List[List[int]]) -> int:
        m, n = len(isInfected), len(isInfected[0])
        ans = 0 
        while True: 
            regions = []
            fronts = []
            walls = []
            seen = set()
            for i in range(m): 
                for j in range(n): 
                    if isInfected[i][j] == 1 and (i, j) not in seen: 
                        seen.add((i, j))
                        stack = [(i, j)]
                        regions.append([(i, j)])
                        fronts.append(set())
                        walls.append(0)
                        while stack: 
                            r, c = stack.pop()
                            for rr, cc in (r-1, c), (r, c-1), (r, c+1), (r+1, c): 
                                if 0 <= rr < m and 0 <= cc < n: 
                                    if isInfected[rr][cc] == 1 and (rr, cc) not in seen: 
                                        seen.add((rr, cc))
                                        stack.append((rr, cc))
                                        regions[-1].append((rr, cc))
                                    elif isInfected[rr][cc] == 0: 
                                        fronts[-1].add((rr, cc))
                                        walls[-1] += 1
            if not regions: break
            idx = fronts.index(max(fronts, key = len))
            ans += walls[idx]
            for i, region in enumerate(regions): 
                if i == idx: 
                    for r, c in region: isInfected[r][c] = -1 # mark as quaranteened 
                else: 
                    for r, c in fronts[i]: isInfected[r][c] = 1 # mark as infected 
        return ans 
