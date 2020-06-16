from crio.ds.Tree.TreeNode import TreeNode

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def wavelistList(first, second, wave, prefix):
    if first:
       fl = len(first)
    else:
       fl = 0

    if second:       
        sl = len(second)
    else:
       sl = 0   
    if fl == 0 or sl == 0:
       tmp = list()
       tmp.extend(prefix)
       if first:
          tmp.extend(first)
       if second:   
          tmp.extend(second)
       wave.append(tmp)
       return

    if fl:
        fitem = first.pop(0)
        prefix.append(fitem)
        wavelistList(first, second, wave, prefix)
        prefix.pop()
        first.insert(0, fitem)

    if sl:
        fitem = second.pop(0)
        prefix.append(fitem)
        wavelistList(first, second, wave, prefix)
        prefix.pop()
        second.insert(0, fitem)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

'''
# Definition of TreeNode
class TreeNode:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None
'''
def inputSequencesForBst(root):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    result = list()
    if root == None:
       return result

    prefix = list()
    prefix.append(root.val)

    leftseq = inputSequencesForBst(root.left)
    rightseq = inputSequencesForBst(root.right)
    lseq = len(leftseq)
    rseq = len(rightseq)

    if lseq and rseq:
       for i in range(lseq):
          for j in range(rseq):
            wave = list()
            wavelistList(leftseq[i], rightseq[j], wave, prefix)
            for k in range(len(wave)):
                result.append(wave[k])

    elif lseq:
      for i in range(lseq):
        wave = list()
        wavelistList(leftseq[i], None, wave, prefix)
        for k in range(len(wave)):
            result.append(wave[k])

    elif rseq:
      for j in range(rseq):
        wave = list()
        wavelistList(None, rightseq[j], wave, prefix)
        for k in range(len(wave)):
            result.append(wave[k])
    else:
        result.append(prefix) 

    return result
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
