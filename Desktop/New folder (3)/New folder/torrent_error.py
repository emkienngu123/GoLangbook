# unicode characters for success/failure indication
SUCCESS = 'SUCCESS'
FAILURE = 'FAIL'

"""
    The user defined class helps in raising user defined expection
    occuring during bittorent client transmission and reception
"""
class torrent_error(RuntimeError): 
    
    def __init__(self, error_msg): 
        self.error_msg = error_msg

    def __str__(self):
        return str(self.error_msg)
