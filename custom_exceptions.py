class InvalidOperationError(Exception):
    """許可されていない操作が行われたときに使う例外クラス"""
    def __init__(self, message="不正な操作が試みられました"):
        self.message = message
        super().__init__(self.message)