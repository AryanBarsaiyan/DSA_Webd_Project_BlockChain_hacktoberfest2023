class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        memory = {}
        
        def explore_state(s_index, p_index):
            if (s_index, p_index) in memory:
                return memory[(s_index, p_index)]
            
            s_index_out_of_border = s_index >= len(s)
            p_index_out_of_border = p_index >= len(p)
            next_char_is_a_star = p_index+1 < len(p) and p[p_index+1] == "*"
            
            if s_index_out_of_border is True:
                if p_index_out_of_border is True:
                    return True
                elif next_char_is_a_star is True:
                    memory[(s_index, p_index)] = explore_state(s_index, p_index+2)
                    return memory[(s_index, p_index)]
                else:
                    memory[(s_index, p_index)] = False
                    return memory[(s_index, p_index)]
                
            if p_index_out_of_border:
                return False
            
            match = s[s_index] == p[p_index] or p[p_index] == "."
            
            if next_char_is_a_star is True and match is True:
                memory[(s_index, p_index)] = explore_state(s_index, p_index+2) or explore_state(s_index+1, p_index)
            elif next_char_is_a_star is True and match is False:
                memory[(s_index, p_index)] = explore_state(s_index, p_index+2)
            elif next_char_is_a_star is False and match is True:
                memory[(s_index, p_index)] = explore_state(s_index+1, p_index+1)
            elif next_char_is_a_star is False and match is False:
                memory[(s_index, p_index)] = False
				
            return memory[(s_index, p_index)]
        
        return explore_state(0, 0)
