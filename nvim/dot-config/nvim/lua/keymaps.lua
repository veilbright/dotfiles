vim.keymap.set("n", "<Esc>", "<cmd>nohlsearch<CR>") -- clear hlsearch
vim.keymap.set({ "n", "v" }, "<leader>ft", "gg=G<C-o>", { desc = "Format tabs" })

-- Switching focus between windows
vim.keymap.set("n", "<C-h>", "<C-w><C-h>", { desc = "Move focus to the left window" })
vim.keymap.set("n", "<C-l>", "<C-w><C-l>", { desc = "Move focus to the right window" })
vim.keymap.set("n", "<C-j>", "<C-w><C-j>", { desc = "Move focus to the lower window" })
vim.keymap.set("n", "<C-k>", "<C-w><C-k>", { desc = "Move focus to the upper window" })

-- Tab management
vim.keymap.set({ "n", "v" }, "<leader>n", "gt", { desc = "Next tab" })
vim.keymap.set({ "n", "v" }, "<leader>p", "gT", { desc = "Previous tab" })

-- Quickfix navigation
vim.keymap.set({ "n", "v" }, "<leader>cn", function()
	if vim.fn.empty(vim.fn.filter(vim.fn.getwininfo(), "v:val.loclist")) == 0 then
		vim.cmd("lnext")
		-- needs to be 2nd, the loclist is a quickfix
	elseif vim.fn.empty(vim.fn.filter(vim.fn.getwininfo(), "v:val.quickfix")) == 0 then
		vim.cmd("cnext")
	end
end, { desc = "Next quickfix" })
vim.keymap.set({ "n", "v" }, "<leader>cp", function()
	if vim.fn.empty(vim.fn.filter(vim.fn.getwininfo(), "v:val.loclist")) == 0 then
		vim.cmd("lprevious")
		-- needs to be 2nd, the loclist is a quickfix
	elseif vim.fn.empty(vim.fn.filter(vim.fn.getwininfo(), "v:val.quickfix")) == 0 then
		vim.cmd("cprevious")
	end
end, { desc = "Previous quickfix" })

-- Clipboard management
vim.keymap.set({ "n", "v" }, "d", '"1d', {})
vim.keymap.set({ "n", "v" }, "x", '"1x', {})
vim.keymap.set({ "n", "v" }, "c", '"1c', {})
vim.keymap.set({ "n", "v" }, "s", '"1s', {})
vim.keymap.set({ "n", "v" }, "<leader>p", function()
	local reg1 = vim.fn.getreginfo("1")
	local reg_plus = vim.fn.getreginfo("+")
	vim.fn.setreg("1", reg_plus)
	vim.fn.setreg("+", reg1)
end, { desc = "Swaps System and Nvim Registers" })

-- Find and replace selection
vim.keymap.set({ "v", "n" }, "<leader>s", function()
	vim.api.nvim_feedkeys("*", "v", true)
	vim.api.nvim_feedkeys(":%s//", "n", true)
end, { desc = "Find and replace" })

-- Toggle Quickfix
vim.keymap.set({ "n", "v" }, "<leader>q", function()
	if vim.fn.empty(vim.fn.filter(vim.fn.getwininfo(), "v:val.loclist")) == 0 then
		vim.cmd("lclose")
		-- needs to be 2nd, the loclist is a quickfix
	elseif vim.fn.empty(vim.fn.filter(vim.fn.getwininfo(), "v:val.quickfix")) == 0 then
		vim.cmd("cclose")
	else
		vim.diagnostic.setloclist()
	end
end, { desc = "Quickfix" })
