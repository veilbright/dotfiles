return {
  'xeluxee/competitest.nvim',
  requires = 'MuniTanjim/nui.nvim',
  config = function()
    require('competitest').setup()
  end,
}
