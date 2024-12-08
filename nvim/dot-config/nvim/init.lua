vim.g.mapleader = " "
vim.g.maplocalleader = " "

require("options")
require("keymaps")
require("lazy-bootstrap")
require("lsp")

vim.cmd.colorscheme("seacarbon")
